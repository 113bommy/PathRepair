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
  return __builtin_popcnt(s);
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
int n;
set<int> S10, S01, S0, S1;
set<string> Sw0, Sw1;
vector<pair<string, string> > res;
map<string, int> M;
string Vs[500005];
pair<string, int> a[500005];
bool flag[500005];
set<string> TT;
string toString(int x) {
  string res = "";
  while (x) {
    res.push_back(x % 10 + '0');
    x /= 10;
  }
  reverse((res).begin(), (res).end());
  return res;
}
string randomString() {
  string res = "aabc";
  while (TT.count(res)) {
    string temp = "";
    for (int i = 0; i < (6); ++i) {
      temp.push_back(rand() % 26 + 'a');
    }
    res = temp;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    string u = toString(i);
    Vs[i] = u;
    M[u] = i;
  }
  int num = 0;
  for (int i = (1); i <= (n); ++i) {
    cin >> a[i].first >> a[i].second;
    TT.insert(a[i].first);
    num += a[i].second;
  }
  memset(flag, 0, sizeof(flag));
  for (int i = (1); i <= (n); ++i) {
    int u = M[a[i].first];
    if (u) {
      flag[u] = 1;
      if (a[i].second == 1 && u > num) {
        S01.insert(u);
      }
      if (a[i].second == 0 && u <= num) {
        S10.insert(u);
      }
    } else {
      if (a[i].second)
        Sw1.insert(a[i].first);
      else
        Sw0.insert(a[i].first);
    }
  }
  for (int i = (1); i <= (n); ++i)
    if (!flag[i]) {
      if (i <= num)
        S1.insert(i);
      else
        S0.insert(i);
    }
  while (((long long)(S01).size()) || ((long long)(S10).size())) {
    bool have = false;
    if (((long long)(S01).size()) && ((long long)(S1).size())) {
      have = true;
      int x = *S01.begin();
      int y = *S1.begin();
      res.push_back(make_pair(Vs[x], Vs[y]));
      S01.erase(x);
      S1.erase(y);
      S0.insert(x);
    }
    if (((long long)(S10).size()) && ((long long)(S0).size())) {
      have = true;
      int x = *S10.begin();
      int y = *S0.begin();
      res.push_back(make_pair(Vs[x], Vs[y]));
      S10.erase(x);
      S0.erase(y);
      S1.insert(x);
    }
    if (!have) {
      int x = *S01.begin();
      string rdS = randomString();
      res.push_back(make_pair(Vs[x], rdS));
      S01.erase(x);
      S0.insert(x);
      Sw1.insert(rdS);
    }
  }
  while (((long long)(Sw0).size())) {
    string u = *Sw0.begin();
    int x = *S0.begin();
    res.push_back(make_pair(u, Vs[x]));
    Sw0.erase(u);
    S0.erase(x);
  }
  while (((long long)(Sw1).size())) {
    string u = *Sw1.begin();
    int x = *S1.begin();
    res.push_back(make_pair(u, Vs[x]));
    Sw1.erase(u);
    S1.erase(x);
  }
  cout << ((long long)(res).size()) << "\n";
  for (int i = 0; i < (((long long)(res).size())); ++i) {
    cout << "move " << res[i].first << " " << res[i].second << "\n";
  }
  return 0;
}
