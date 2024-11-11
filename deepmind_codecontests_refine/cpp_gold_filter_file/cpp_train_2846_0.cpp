#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
  return {l.first + r.first, l.second + r.second};
}
typedef void (*callback_function)(void);
const long long INF64 = 1e18;
const int INF32 = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  {
    int n, m, c;
    cin >> n >> m >> c;
    int a[n];
    for (int i = (0); i < (n); i++) cin >> a[i];
    int b[m];
    for (int i = (0); i < (m); i++) cin >> b[i];
    int s[m + 1];
    s[0] = 0;
    for (int i = (0); i < (m); i++) s[i + 1] = (s[i] + b[i]) % c;
    for (int i = (0); i < (n); i++) {
      int right = min(m - 1, i);
      int left = max(0, i - n + m);
      a[i] = (a[i] + (s[right + 1] - s[left] + c)) % c;
    }
    for (int i = (0); i < (n); i++) cout << a[i] % c << ' ';
    cout << endl;
  }
  return 0;
}
