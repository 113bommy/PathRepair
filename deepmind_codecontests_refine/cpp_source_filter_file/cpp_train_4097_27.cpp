#include <bits/stdc++.h>
using namespace std;
char a[1000001], b[1000001];
int main() {
  scanf("%s", a);
  int l = strlen(a);
  for (int i = l - 1; i >= 0; i--) {
    b[i] = max(b[i + 1], a[i]);
  }
  for (int i = 0; i <= l; i++) {
    if (a[i] == b[i]) {
      cout << a[i];
    }
  }
  return 0;
}
