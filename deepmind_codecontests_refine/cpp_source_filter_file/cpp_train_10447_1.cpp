#include <bits/stdc++.h>
using namespace std;
const int mod = 32700;
const int maxn = 1000100;
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
inline int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
char orig_str[maxn];
int nqu, l;
short dp[(1 << 26) + 10];
char dp1[(1 << 26) + 10];
int ans[1010];
char que[27], lque = 0;
int main() {
  scanf("%s", orig_str);
  scanf("%d", &nqu);
  for (int i = 0; i < nqu; i++) {
    char ranstr[maxn];
    scanf("%s", ranstr);
    int ranl = strlen(ranstr);
    int temp = 0;
    for (int j = 0; j < ranl; j++) temp |= 1 << (ranstr[j] - 'a');
    ans[i] = temp;
  }
  int l = strlen(orig_str);
  memset(que, -1, sizeof(que));
  for (int i = 0; i < l; i++) {
    int j = 0;
    for (; j < lque; j++)
      if (orig_str[i] == que[j]) break;
    for (int k = j; k > 0; k--) que[k] = que[k - 1];
    que[0] = orig_str[i];
    int temp = 0;
    for (int k = 0; k < (j == lque ? j + 1 : j); k++) {
      temp |= (1 << que[k] - 'a');
      dp[temp]++;
      if (dp[temp] == mod) {
        dp[temp] = 0;
        dp1[temp]++;
      }
    }
    if (j == lque) lque++;
  }
  for (int i = 0; i < nqu; i++)
    printf("%d\n", int(dp[ans[i]]) + mod * dp1[ans[i]]);
  return 0;
}
