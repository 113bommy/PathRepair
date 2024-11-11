#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _dbg(const char* _s, T _h) {
  cerr << _s << " = " << _h << "\n";
}
template <typename T, typename... Ts>
void _dbg(const char* _s, T _h, Ts... _t) {
  int _b = 0;
  while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',') cerr << *_s++;
  cerr << " = " << _h << ",";
  _dbg(_s + 1, _t...);
}
const int64_t INF = static_cast<int64_t>(1e9) + 7;
const int64_t LINF = INF * INF;
const int MAXN = static_cast<int>(1e6) + 17;
int n;
bool read() {
  if (cin >> n) {
    return true;
  }
  return false;
}
void solve() {
  vector<int> vec(n);
  for (int i = 0; i < static_cast<int>(n); ++i) {
    cin >> vec[i];
  }
  int first = vec[0];
  int last;
  for (int i = 0; i < static_cast<int>(n); ++i) {
    if (vec[i] != first) {
      last = i;
    }
  }
  int l = vec[n - 1];
  int fir;
  for (int i = 0; i < static_cast<int>(n); ++i) {
    if (vec[i] != l) {
      fir = i;
      break;
    }
  }
  cout << max(last, n - fir - 1) << '\n';
}
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  while (read()) solve();
  return 0;
}
