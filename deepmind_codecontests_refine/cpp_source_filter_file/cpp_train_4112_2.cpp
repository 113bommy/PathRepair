#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
int pw(int a, int n) {
  int ans = 1;
  while (n) {
    if (n % 2 == 1) {
      ans = ans * a;
      n--;
    } else {
      a = a * a;
      n = n / 2;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, i;
  cin >> n;
  long long ans;
  ans = min(9, n);
  for (i = 1; i <= 9; i++) {
    if (n > pow(10, i) - 1) {
      ans += (min(pw(10, i + 1) - 1, n) - (pw(10, i) - 1)) * (i + 1);
    }
  }
  cout << ans << endl;
  return 0;
}
