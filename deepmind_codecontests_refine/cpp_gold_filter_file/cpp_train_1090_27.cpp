#include <bits/stdc++.h>
using namespace std;
long long h, n;
long long ans = 0;
int main() {
  cin >> h >> n;
  int h1 = h;
  while (h1) {
    ans++;
    if (h1 == 1 && n == 2) {
      ans += pow(2, h - h1 + 1) - 1;
      h1--;
      continue;
    }
    if (h1 == 1) {
      h1--;
      continue;
    }
    if (n % 2 == 0 && n % 4 == 0) {
      ans += pow(2, h - h1 + 1) - 1;
      n = n / 2;
    } else if (n % 2 != 0 && (n + 1) % 4 != 0) {
      ans += pow(2, h - h1 + 1) - 1;
      n = (n + 1) / 2;
    } else if (n % 2 == 0)
      n /= 2;
    else
      n = (n + 1) / 2;
    h1--;
  }
  cout << ans;
}
