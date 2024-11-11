#include <bits/stdc++.h>
using namespace std;
long long a, b, n, ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a, &b);
    if (a % 2 == 0) {
      ans = ans ^ a;
      ++a;
      --b;
    }
    if (b != 0 && b % 2 != 0) {
      ans = ans ^ (a + b - 1);
      --b;
    }
    if (b != 0 && (b / 2) % 2 != 0) {
      ans = ans ^ 1;
    }
  }
  if (ans != 0) {
    cout << "tolik" << endl;
  }
  if (ans == 0) {
    cout << "bolik" << endl;
  }
}
