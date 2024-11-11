#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int M = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long d, c, m;
  cin >> d >> c >> m;
  vector<array<long long, 2>> A(m);
  for (int i = 0; i < m; ++i) {
    cin >> A[i][0] >> A[i][1];
  }
  A.push_back({d, 0});
  A.insert(A.begin(), {0, 0});
  sort(A.begin(), A.end());
  m += 2;
  long long ans = 0;
  int i = 0;
  int j = 0;
  long long pv = 0;
  while (i < m - 1) {
    j = max(j, i + 1);
    int mnind = -1;
    while (j < m && A[j][0] - A[i][0] <= c) {
      if (A[j][1] <= A[i][1]) {
        mnind = j;
        break;
      }
      if (mnind == -1) {
        mnind = j;
      } else {
        if (A[mnind][1] >= A[j][1]) {
          mnind = j;
        }
      }
      ++j;
    }
    if (mnind == -1) {
      cout << -1 << "\n";
      return 0;
    }
    long long dist = A[mnind][0] - A[i][0];
    if (A[mnind][1] <= A[i][1]) {
      ans += max(0LL, (dist - pv) * (A[i][1]));
      pv = max(0LL, pv - (dist));
    } else {
      ans += (c - pv) * (A[i][1]);
      pv = c - dist;
    }
    i = mnind;
  }
  cout << ans << "\n";
  return 0;
}
