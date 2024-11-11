#include <bits/stdc++.h>
using namespace std;
char t[200050], p[200050];
int a[200050], b[200050];
int main() {
  string t1, p1;
  scanf("%s", t);
  scanf("%s", p);
  int i = 0, ai;
  p1 = string(p);
  while (scanf("%d", &ai) != EOF) a[i++] = ai - 1;
  int l = 0, r = i - 1, mid;
  while (l <= r) {
    string r1 = string(t);
    mid = (l + r) / 2;
    for (i = 0; i <= mid; i++) r1[a[i]] = '_';
    int j = 0, pos = 0;
    while (j < strlen(t)) {
      if (r1[j] == p[pos]) pos++;
      j++;
    }
    if (pos >= strlen(p))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << l << endl;
  return 0;
}
