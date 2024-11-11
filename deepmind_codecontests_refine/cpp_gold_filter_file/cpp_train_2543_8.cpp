#include <bits/stdc++.h>
using namespace std;
int a[2000], N;
long long ans[2000], an;
int main() {
  int i, j;
  cin >> N;
  for (i = 1; i <= N; i++) cin >> a[i];
  ans[1] = 2;
  for (i = 2; i <= N; i++) {
    ans[i] = 2;
    for (j = a[i]; j < i; j++) ans[i] = (ans[i] + ans[j]) % 1000000007;
  }
  an = 0;
  for (i = 1; i <= N; i++) an = (an + ans[i]) % 1000000007;
  cout << an << endl;
  return 0;
}
