#include <bits/stdc++.h>
using namespace std;
char ans[100005] = {};
long long arr[100005] = {};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  long long cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    int def1 = cur + arr[i];
    int def2 = -cur + arr[i];
    if (def1 < def2)
      ans[i] = '+', cur += arr[i];
    else
      ans[i] = '-', cur -= arr[i];
  }
  if (cur < 0)
    for (int i = 0; i < n; ++i)
      if (ans[i] == '-')
        ans[i] = '+';
      else
        ans[i] = '-';
  cout << ans << endl;
  return 0;
}
