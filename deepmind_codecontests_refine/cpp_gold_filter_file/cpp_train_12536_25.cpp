#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[200000 + 10];
int main() {
  cin >> n;
  int lookright = 0;
  int lookleft = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    if (tmp == 1) {
      lookright++;
    }
    if (tmp == 0) {
      lookleft++;
      arr[i] = lookright;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += arr[i];
  }
  cout << ans << endl;
  return 0;
}
