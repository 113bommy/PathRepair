#include <bits/stdc++.h>
using namespace std;
char A[256];
char a[100005];
int main() {
  gets(a);
  char *cad = a;
  while (*cad) {
    A[*cad]++;
    cad++;
  }
  long long ans = 0;
  for (int i = '0'; i <= 'z'; ++i) {
    ans += (long long)(A[i]) * (long long)(A[i]);
  }
  cout << ans << endl;
  return 0;
}
