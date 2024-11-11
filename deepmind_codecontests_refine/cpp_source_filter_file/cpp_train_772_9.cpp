#include <bits/stdc++.h>
using namespace std;
char str[202];
int k;
int n;
bool valid(int l) {
  int ans = 0;
  for (int i = 0; i + l < n; i++) {
    if (str[i] == str[i + l]) {
      ans++;
    } else {
      ans = 0;
    }
    if (ans == l) {
      return true;
    }
  }
  if (k + ans >= l) {
    return true;
  }
  return false;
}
int bs() {
  int ans = 0;
  for (int i = 2; i <= (k + n) / 2 * 2; i++) {
    if (valid(i)) {
      ans = max(ans, i);
    }
  }
  return ans;
}
int main() {
  scanf("%s", &str);
  scanf("%d", &k);
  n = strlen(str);
  if (k >= n) {
    printf("%d", (k + n) * 2 / 2);
    return 0;
  }
  printf("%d", bs() * 2);
}
