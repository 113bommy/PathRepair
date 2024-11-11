#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const double eps = 1e-8;
char a[MAXN], b[MAXN];
int c1[MAXN], c2[MAXN];
int main() {
  scanf("%s %s", a + 1, b + 1);
  int lena = strlen(a + 1);
  int lenb = strlen(b + 1);
  int max_len = 0;
  int j = 1, i;
  for (i = 1; i <= lena; i++) {
    if (a[i] == b[j]) {
      c1[j] = i;
      j++;
      if (j == lenb + 1) break;
      continue;
    }
  }
  max_len = max(max_len, lena - i);
  j = lenb;
  for (i = lena; i >= 1; i--) {
    if (a[i] == b[j]) {
      c2[j] = i;
      j--;
      if (j == 0) break;
      continue;
    }
  }
  max_len = max(max_len, i - 1);
  for (i = 1; i <= lenb; i++) {
    if (i == 1)
      max_len = max(max_len, c2[i] - c1[i]);
    else
      max_len = max(max_len, c2[i] - c1[i - 1] - 1);
  }
  cout << max_len << endl;
}
