#include <bits/stdc++.h>
using namespace std;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcountll(s);
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
long long n, L, d;
int RR[2025];
long long f[2025][2025];
map<pair<int, long long>, long long> M;
long long cal(int id, long long x) {
  if (M[make_pair(id, x)]) return M[make_pair(id, x)] - 1;
  fflush(stdout);
  cout << "? " << id << " " << x << endl;
  long long res;
  cin >> res;
  M[make_pair(id, x)] = res + 1;
  return res;
}
long long find(int id, int vt) {
  long long &res = f[id][vt];
  if (res != -1) return res;
  long long x = vt * d;
  long long l = 0, r = (long long)(1e18);
  while (l < r) {
    long long mid = (l + r) / 2;
    if (cal(id, mid) < x)
      l = mid + 1;
    else
      r = mid;
  }
  res = l;
  return res;
}
pair<vector<int>, vector<int> > divide(vector<int> V, int u, int v, int k) {
  int len = (v - u + 1);
  int id = V[rand() % len];
  long long vt = find(id, k);
  vector<int> behon, lonhon, bang;
  for (int i = 0; i < (((int)(V).size())); ++i) {
    int x = V[i];
    long long y = cal(x, vt);
    if (y > k * d)
      behon.push_back(x);
    else if (y == k * d)
      bang.push_back(x);
    else
      lonhon.push_back(x);
  }
  pair<vector<int>, vector<int> > res;
  if (((int)(behon).size()) > k - u) {
    pair<vector<int>, vector<int> > temp =
        divide(behon, u, u + ((int)(behon).size()) - 1, k);
    res = temp;
    for (int i = 0; i < (((int)(bang).size())); ++i)
      res.second.push_back(bang[i]);
    for (int i = 0; i < (((int)(lonhon).size())); ++i)
      res.second.push_back(lonhon[i]);
    temp.first.clear();
    temp.second.clear();
  } else if (((int)(lonhon).size()) > v - k) {
    pair<vector<int>, vector<int> > temp =
        divide(lonhon, v - ((int)(lonhon).size()) + 1, v, k);
    res = temp;
    for (int i = 0; i < (((int)(behon).size())); ++i)
      res.first.push_back(behon[i]);
    for (int i = 0; i < (((int)(bang).size())); ++i)
      res.first.push_back(bang[i]);
    temp.first.clear();
    temp.second.clear();
  } else {
    for (int i = 0; i < (((int)(behon).size())); ++i)
      res.first.push_back(behon[i]);
    for (int i = 0; i < (((int)(bang).size())); ++i) {
      if (((int)(res.first).size()) < k - u + 1)
        res.first.push_back(bang[i]);
      else
        res.second.push_back(bang[i]);
    }
    for (int i = 0; i < (((int)(lonhon).size())); ++i)
      res.second.push_back(lonhon[i]);
  }
  V.clear();
  behon.clear();
  bang.clear();
  lonhon.clear();
  return res;
}
void go(vector<int> V, int u, int v) {
  int mid = (u + v) / 2;
  int len = (v - u + 1);
  if (u == v) {
    RR[V[0]] = u;
    return;
  }
  pair<vector<int>, vector<int> > VV = divide(V, u, v, mid);
  go(VV.first, u, mid);
  go(VV.second, mid + 1, v);
}
void sol() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(NULL));
  memset(f, -1, sizeof(f));
  cin >> n >> L;
  d = L / n;
  vector<int> V;
  for (int i = (1); i <= (n); ++i) V.push_back(i);
  go(V, 1, n);
  vector<long long> vv;
  vv.push_back(0);
  for (int i = (1); i <= (n); ++i) vv.push_back(find(i, RR[i]));
  sort((vv).begin(), (vv).end());
  cout << "!" << endl;
  for (int i = (1); i <= (n); ++i)
    cout << vv[RR[i] - 1] << " " << vv[RR[i]] << endl;
}
int main() {
  sol();
  return 0;
}
