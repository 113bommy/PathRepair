#include <bits/stdc++.h>
using namespace std;
bool ch[10005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= (n + 1) / 2; i++) {
    if (!ch[i + 1]) {
      printf("%d ", i + 1);
      ch[i + 1] = true;
    }
    if (!ch[n - i]) {
      printf("%d ", n - i);
      ch[n - i] = true;
    }
  }
  return 0;
}
