#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int cou[27];
int main() {
  char str[maxn];
  scanf("%s", str);
  memset(cou, 0, sizeof(cou));
  int len = strlen(str);
  if (len < 4) {
    puts("No");
    return 0;
  }
  for (int i = 0; i < len; i++) {
    cou[str[i] - 'a']++;
  }
  int ans = 0;
  int stac[26], top = 0;
  for (int i = 0; i < 26; i++) {
    if (cou[i]) stac[top++] = cou[i], ans++;
  }
  if (ans == 4)
    puts("Yes");
  else if (ans == 3) {
    if (stac[0] > 1 || stac[1] > 1 || stac[2] > 1)
      puts("Yes");
    else
      puts("No");
  } else if (ans == 2) {
    if (stac[0] >= 2 && stac[1] >= 2)
      puts("Yes");
    else
      puts("No");
  } else
    puts("No");
  return 0;
}
