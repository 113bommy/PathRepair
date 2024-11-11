#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
inline void outarr(Tp _array, const std::size_t _N, const char* _delim = " ") {
  Tp end = _array + _N;
  for (Tp current = _array; current != end; ++current) {
    std::cout << *current << _delim;
  }
  std::cout << '\n';
}
using ll = uint64_t;
using pii = std::pair<int, int>;
constexpr int INF = INT_MAX;
constexpr int MOD = static_cast<const int>(1e9 + 7);
int arr[200001];
map<int, int> cnt;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> arr[i];
  }
  ll sum = arr[0];
  cnt[arr[0]] = 1;
  ll ans = 0;
  bool signm = false;
  for (int i = (1); i < (n); ++i) {
    ll diff = 0;
    ll count = i;
    if (cnt.find(arr[i]) != cnt.end()) {
      diff += (ll)cnt[arr[i]] * arr[i];
      count -= cnt[arr[i]];
    }
    if (cnt.find(arr[i] - 1) != cnt.end()) {
      diff += (ll)cnt[arr[i] - 1] * (arr[i] - 1);
      count -= cnt[arr[i] - 1];
    }
    if (cnt.find(arr[i] + 1) != cnt.end()) {
      diff += (ll)cnt[arr[i] + 1] * (arr[i] + 1);
      count -= cnt[arr[i] + 1];
    }
    long long tmp = count * arr[i] - sum + diff;
    if (signm) {
      if (tmp > 0 && tmp > ans) {
        ans = tmp - ans;
        signm = false;
      } else {
        ans -= tmp;
      }
    } else {
      if (tmp < 0 && abs(tmp) > ans) {
        ans = abs(tmp) - ans;
        signm = true;
      } else {
        ans += tmp;
      }
    }
    sum += arr[i];
    ++cnt[arr[i]];
  }
  if (signm && ans) {
    cout << "-";
  }
  cout << ans;
  return 0;
}
