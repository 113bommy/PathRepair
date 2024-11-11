#include <bits/stdc++.h>
using namespace std;
long long a, b;
int s[] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6};
int main() {
  long long ans = 0;
  cin >> a >> b;
  for (long long i = a; i <= b; i++) {
    for (long long j = i; j > 0; j /= 10) {
      ans += s[j % 10];
    }
  }
  cout << ans;
  return 0;
}
