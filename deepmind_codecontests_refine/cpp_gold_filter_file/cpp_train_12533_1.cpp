#include <bits/stdc++.h>
using namespace std;
char in[100005];
long long P(long long n, long long r) {
  long long ans = 1;
  for (int i = n - r + 1; i <= n; i++) ans = ans * i;
  return ans;
}
int main() {
  long long i, l, ans, j, x = 0, a = 0, b, subtr = 0;
  int A[27] = {0}, B[26] = {0};
  scanf("%s", in);
  for (i = 0; in[i] != '\0'; i++) {
    if (in[i] == '?')
      x++;
    else if (in[i] >= 'A' && in[i] <= 'J')
      A[in[i] - 'A' + 1]++;
  }
  for (i = 0; i <= 26; i++)
    if (A[i] != 0) a++;
  ans = P(10, a);
  if (in[0] >= 'A' && in[0] <= 'J') {
    subtr = P(9, a - 1);
  } else if (in[0] == '?') {
    ans = ans * 9;
    x--;
  }
  cout << ans - subtr;
  for (i = 0; i < x; i++) printf("0");
  cout << endl;
  return 0;
}
