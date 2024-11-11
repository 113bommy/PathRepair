#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000010;
const long long BASE = 1000000007;
char s[MAX];
long long a, b;
int n;
long long hash1[MAX], hash2[MAX];
int main() {
  scanf("%s%I64d%I64d", s + 1, &a, &b);
  n = strlen(s + 1);
  hash1[0] = 0;
  for (int i = 1; i <= n; i++) {
    hash1[i] = (hash1[i - 1] * 10 + s[i] - 48) % a;
  }
  hash2[n] = (s[n] - 48) % b;
  long long exp = 10;
  for (int i = n - 1; i > 0; i--) {
    hash2[i] = ((long long)(s[i] - 48) * exp + hash2[i + 1]) % b;
    exp *= 10;
    exp %= b;
  }
  for (int i = 2; i <= n; i++) {
    if (s[i] != '0' && hash1[i - 1] == 0 && hash2[i] == 0) {
      printf("YES\n");
      for (int j = 1; j < i; j++) printf("%c", s[j]);
      printf("\n");
      for (int j = i; j <= n; j++) printf("%c", s[j]);
      return 0;
    }
  }
  printf("NO");
}
