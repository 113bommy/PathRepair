#include <bits/stdc++.h>
using namespace std;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
const long long int inf = 1e18;
const long long int MOD = 998244353;
const long long int range = 250;
template <class T>
T mx(T begin, T end) {
  return max_element(begin, end);
}
template <class T>
T mn(T begin, T end) {
  return min_element(begin, end);
}
template <class T>
void print(vector<T> nums) {
  for (T i : nums) cout << i << " ";
  cout << "\n";
}
template <class T>
void read(vector<T>& nums) {
  for (T& i : nums) cin >> i;
}
template <class T>
void alloc(vector<vector<T>*> nums, T n) {
  for (auto v : nums) v->resize(n + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "FastestFinger\n";
      continue;
    }
    if (n == 2) {
      cout << "Ashishgup\n";
      continue;
    }
    if (n & 1) {
      cout << "Ashishgup";
    } else {
      if (!(n & (n - 1))) {
        cout << "FastestFinger";
      } else if ((n / 2) % 2 == 0) {
        cout << "Ashishgup";
      } else {
        int b = 0, temp = n;
        for (int i = 2; i * i <= n; ++i) {
          if (temp % i == 0) {
            int cnt = 0;
            while (temp % i == 0) {
              temp /= i;
              cnt++;
            }
            if (i & 1) {
              b += cnt;
            }
          }
        }
        if (temp > 1) b++;
        if (b > 2) {
          cout << "Ashishgup";
        } else {
          cout << "FastestFinger";
        }
      }
    }
    cout << "\n";
  }
  return 0;
}
