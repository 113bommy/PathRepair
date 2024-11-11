#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) {
    if (vi != v.begin()) os << ", ";
    os << *vi;
  }
  os << "}";
  return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  os << '(' << p.first << ", " << p.second << ')';
  return os;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long T, N, M, K;
long long qtd11, minAns;
vector<pair<int, int> > v[4];
int nums[200010];
int menor(vector<int> &ptr) {
  pair<int, int> ans(0x3f3f3f3f, 0x3f3f3f3f);
  int pos = -1;
  for (int i = 0; i < 4; i++) {
    if (ptr[i] < v[i].size() && ans >= v[i][ptr[i]]) {
      ans = v[i][ptr[i]];
      pos = i;
    }
  }
  return pos;
}
void imp() {
  cout << -1 << "\n";
  exit(0);
}
pair<int, int> p(pair<int, int> a) {
  return pair<int, int>(-a.first, -a.second);
}
void melhor() {
  for (int i = 0; i < 4; i++) sort(v[i].begin(), v[i].end());
  vector<pair<int, int> > resp[4];
  vector<int> ptr(4, 0);
  long long ans = 0, l11 = max(0LL, 2 * M - K), l01;
  l01 = M - l11;
  if (v[0].size() < l11) imp();
  for (; ptr[0] < l11; ptr[0]++) {
    resp[0].push_back(v[0][ptr[0]]);
    ans += v[0][ptr[0]].first;
  }
  while (ptr[0] < v[0].size() && (v[1].size() < l01 || v[2].size() < l01)) {
    l01--;
    resp[0].push_back(v[0][ptr[0]]);
    ans += v[0][ptr[0]].first;
    ptr[0]++;
  }
  while (ptr[0] < v[0].size() &&
         ptr[0] + v[1].size() + v[2].size() + v[3].size() < K) {
    l01--;
    resp[0].push_back(v[0][ptr[0]]);
    ans += v[0][ptr[0]].first;
    ptr[0]++;
  }
  if (v[1].size() < l01 || v[2].size() < l01) imp();
  for (; ptr[1] < l01; ptr[1]++, ptr[2]++) {
    resp[1].push_back(v[1][ptr[1]]);
    resp[2].push_back(v[2][ptr[2]]);
    ans += v[1][ptr[1]].first;
    ans += v[2][ptr[2]].first;
  }
  priority_queue<pair<int, int> > sob, others;
  for (int i = 1; i < 4; i++) {
    for (int j = ptr[i]; j < v[i].size(); j++) {
      sob.push(p(v[i][j]));
    }
  }
  while (!sob.empty() && ptr[0] + ptr[1] + ptr[2] + others.size() < K) {
    ans += -sob.top().first;
    others.push(p(sob.top()));
    sob.pop();
  }
  minAns = ans;
  qtd11 = ptr[0];
  for (; ptr[1] && ptr[0] < v[0].size(); ptr[0]++) {
    ptr[1]--, ptr[2]--;
    sob.push(p(resp[1][ptr[1]]));
    ans -= resp[1][ptr[1]].first;
    resp[1].pop_back();
    sob.push(p(resp[2][ptr[2]]));
    ans -= resp[2][ptr[2]].first;
    resp[2].pop_back();
    resp[0].push_back(v[0][ptr[0]]);
    ans += v[0][ptr[0]].first;
    pair<int, int> u = p(sob.top());
    sob.pop();
    others.push(u);
    ans += u.first;
    while (others.top() > p(sob.top())) {
      pair<int, int> aux = others.top();
      pair<int, int> aux2 = p(sob.top());
      ans -= aux.first;
      ans += aux2.first;
      others.pop();
      sob.pop();
      others.push(aux2);
      sob.push(p(aux));
    }
    if (ans < minAns) {
      qtd11 = resp[0].size();
      minAns = ans;
    }
  }
}
void construir() {
  vector<pair<int, int> > resp;
  vector<int> ptr(4, 0);
  long long ans = 0;
  for (; ptr[0] < qtd11; ptr[0]++) {
    resp.push_back(v[0][ptr[0]]);
    ans += v[0][ptr[0]].first;
  }
  for (int i = qtd11; i < M; i++, ptr[1]++, ptr[2]++) {
    resp.push_back(v[1][ptr[1]]);
    resp.push_back(v[2][ptr[2]]);
    ans += v[1][ptr[1]].first;
    ans += v[2][ptr[2]].first;
  }
  while (resp.size() < K) {
    int pos = menor(ptr);
    ans += v[pos][ptr[pos]].first;
    resp.push_back(v[pos][ptr[pos]]);
    ptr[pos]++;
  }
  cout << ans << "\n";
  for (int i = 0; i < resp.size(); i++) {
    if (!i)
      cout << resp[i].second + 1;
    else
      cout << " " << resp[i].second + 1;
  }
  cout << "\n";
}
void solve() {
  melhor();
  construir();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> N >> K >> M;
  for (int i = 0; i < N; i++) {
    int a, b, t;
    cin >> t >> a >> b;
    if (a && b) {
      v[0].push_back(pair<int, int>(t, i));
    } else if (a) {
      v[1].push_back(pair<int, int>(t, i));
    } else if (b) {
      v[2].push_back(pair<int, int>(t, i));
    } else {
      v[3].push_back(pair<int, int>(t, i));
    }
    nums[i] = t;
  }
  solve();
  return 0;
}
