#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}
const int mod = 1e9 + 7;
void solve() {
  int nr, ng, nb;
  cin >> nr >> ng >> nb;
  vector<long long> red(nr), green(ng), blue(nb);
  for (int i = 0; i < nr; i++) cin >> red[i];
  for (int i = 0; i < ng; i++) cin >> green[i];
  for (int i = 0; i < nb; i++) cin >> blue[i];
  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end());
  sort(green.begin(), green.end());
  long long ans = LLONG_MAX, xans, yans, zans;
  for (int i = 0; i < nr; i++) {
    auto itr = lower_bound(green.begin(), green.end(), red[i]);
    if (itr != green.end()) {
      long long tempgreen = *itr;
      auto ptr = lower_bound(blue.begin(), blue.end(), red[i]);
      if (ptr != blue.end()) {
        long long tempblue = *ptr;
        long long tempans = (red[i] - tempgreen) * (red[i] - tempgreen) +
                            (tempgreen - tempblue) * (tempgreen - tempblue) +
                            (tempblue - red[i]) * (tempblue - red[i]);
        ans = min(ans, tempans);
      }
      if (ptr != blue.begin()) {
        ptr--;
        long long tempblue = *ptr;
        long long tempans = (red[i] - tempgreen) * (red[i] - tempgreen) +
                            (tempgreen - tempblue) * (tempgreen - tempblue) +
                            (tempblue - red[i]) * (tempblue - red[i]);
        ans = min(ans, tempans);
      }
    }
    if (itr != green.begin()) {
      itr--;
      long long tempgreen = *itr;
      auto ptr = lower_bound(blue.begin(), blue.end(), red[i]);
      if (ptr != blue.end()) {
        long long tempblue = *ptr;
        long long tempans = (red[i] - tempgreen) * (red[i] - tempgreen) +
                            (tempgreen - tempblue) * (tempgreen - tempblue) +
                            (tempblue - red[i]) * (tempblue - red[i]);
        ans = min(ans, tempans);
      }
      if (ptr != blue.begin()) {
        ptr--;
        long long tempblue = *ptr;
        long long tempans = (red[i] - tempgreen) * (red[i] - tempgreen) +
                            (tempgreen - tempblue) * (tempgreen - tempblue) +
                            (tempblue - red[i]) * (tempblue - red[i]);
        ans = min(ans, tempans);
      }
    }
  }
  for (int i = 0; i < ng; i++) {
    auto itr = lower_bound(red.begin(), red.end(), green[i]);
    if (itr != red.end()) {
      long long tempred = *itr;
      auto ptr = lower_bound(blue.begin(), blue.end(), green[i]);
      if (ptr != blue.end()) {
        long long tempblue = *ptr;
        long long tempans = (green[i] - tempred) * (green[i] - tempred) +
                            (tempred - tempblue) * (tempred - tempblue) +
                            (tempblue - green[i]) * (tempblue - green[i]);
        ans = min(ans, tempans);
      }
      if (ptr != blue.begin()) {
        ptr--;
        long long tempblue = *ptr;
        long long tempans = (green[i] - tempred) * (green[i] - tempred) +
                            (tempred - tempblue) * (tempred - tempblue) +
                            (tempblue - green[i]) * (tempblue - green[i]);
        ans = min(ans, tempans);
      }
    }
    if (itr != red.begin()) {
      itr--;
      long long tempred = *itr;
      auto ptr = lower_bound(blue.begin(), blue.end(), green[i]);
      if (ptr != blue.end()) {
        long long tempblue = *ptr;
        long long tempans = (green[i] - tempred) * (green[i] - tempred) +
                            (tempred - tempblue) * (tempred - tempblue) +
                            (tempblue - green[i]) * (tempblue - green[i]);
        ans = min(ans, tempans);
      }
      if (ptr != blue.begin()) {
        ptr--;
        long long tempblue = *ptr;
        long long tempans = (green[i] - tempred) * (green[i] - tempred) +
                            (tempred - tempblue) * (tempred - tempblue) +
                            (tempblue - green[i]) * (tempblue - green[i]);
        ans = min(ans, tempans);
      }
    }
  }
  for (int i = 0; i < nb; i++) {
    auto itr = lower_bound(red.begin(), red.end(), blue[i]);
    if (itr != red.end()) {
      long long tempred = *itr;
      auto ptr = lower_bound(green.begin(), green.end(), blue[i]);
      if (ptr != green.end()) {
        long long tempgreen = *ptr;
        long long tempans = (blue[i] - tempred) * (blue[i] - tempred) +
                            (tempred - tempgreen) * (tempred - tempgreen) +
                            (tempgreen - blue[i]) * (tempgreen - blue[i]);
        ans = min(ans, tempans);
      }
      if (ptr != blue.begin()) {
        ptr--;
        long long tempgreen = *ptr;
        long long tempans = (blue[i] - tempred) * (blue[i] - tempred) +
                            (tempred - tempgreen) * (tempred - tempgreen) +
                            (tempgreen - blue[i]) * (tempgreen - blue[i]);
        ans = min(ans, tempans);
      }
    }
    if (itr != red.begin()) {
      itr--;
      long long tempred = *itr;
      auto ptr = lower_bound(green.begin(), green.end(), blue[i]);
      if (ptr != green.end()) {
        long long tempgreen = *ptr;
        long long tempans = (blue[i] - tempred) * (blue[i] - tempred) +
                            (tempred - tempgreen) * (tempred - tempgreen) +
                            (tempgreen - blue[i]) * (tempgreen - blue[i]);
        ans = min(ans, tempans);
      }
      if (ptr != blue.begin()) {
        ptr--;
        long long tempgreen = *ptr;
        long long tempans = (blue[i] - tempred) * (blue[i] - tempred) +
                            (tempred - tempgreen) * (tempred - tempgreen) +
                            (tempgreen - blue[i]) * (tempgreen - blue[i]);
        ans = min(ans, tempans);
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tt;
  cin >> tt;
  while (tt--) solve();
}
