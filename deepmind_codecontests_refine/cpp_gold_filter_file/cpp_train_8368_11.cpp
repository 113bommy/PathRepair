#include <bits/stdc++.h>
long long mod = 1000000007;
long long ost[201];
int main(int argc, const char* argv[]) {
  char str[110];
  ost[0] = 1;
  for (int i = 1; i <= 200; i++) ost[i] = (ost[i - 1] * 2) % mod;
  scanf("%s", str);
  int len = strlen(str);
  long long count = 0;
  for (int i = 0; i < len; i++)
    if (str[i] == '1') count = (count + ost[2 * len - 2 - i]) % mod;
  std::cout << count;
  return 0;
}
