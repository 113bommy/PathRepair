#include <bits/stdc++.h>
using namespace std;
string a, b;
int n;
int Next[1000010];
void change() {
  for (int i = 0; i < n - 1; i++) {
    if (b[i] == 'W')
      b[i] = 'E';
    else if (b[i] == 'S')
      b[i] = 'N';
    else if (b[i] == 'N')
      b[i] = 'S';
    else if (b[i] == 'E')
      b[i] = 'W';
  }
  reverse(b.begin(), b.end());
  return;
}
void NEXT() {
  for (int i = 1; i < n - 1; i++) {
    int j = i;
    while (j > 0) {
      j = Next[j];
      if (b[j] == b[i]) {
        Next[i + 1] = j + 1;
        break;
      }
    }
  }
  return;
}
void kmp() {
  int j = 0;
  for (int i = 0; i < n - 1; i++) {
    while (j && b[j + 1] != a[i]) j = Next[j];
    if (b[j + 1] == a[i]) j++;
  }
  if (j == 0)
    printf("YES\n");
  else
    printf("NO\n");
}
int main() {
  scanf("%d", &n);
  cin >> a >> b;
  change();
  NEXT();
  kmp();
}
