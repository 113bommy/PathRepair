#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int n;
int k;
bool shuzu[110];
int main() {
  long long ans = 0;
  cin >> n >> k;
  if (k == n) {
    cout << 0;
    return 0;
  } else {
    for (long long i = 0; i < n; i++) {
      int c;
      cin >> c;
      c--;
      shuzu[i] = c;
    }
    for (long long i = 0; i < n / k; i++) {
      int one, zero;
      one = zero = 0;
      for (int j = i; j < n; j += k) {
        if (shuzu[j]) {
          one++;
        } else {
          zero++;
        }
      }
      ans += min(one, zero);
    }
    cout << ans;
  }
  return 0;
}
