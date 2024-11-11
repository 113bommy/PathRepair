#include <bits/stdc++.h>
using namespace std;
bool cmp1(int a, int b) { return a > b; }
bool cmp2(pair<int, int> a, pair<int, int> b) { return a > b; }
int a[300000], c[300000];
pair<int, int> b[300000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i].first);
    b[i].second = i;
  }
  sort(a, a + n, cmp1);
  sort(b, b + n, cmp2);
  stack<int> stc;
  int loca = 0;
  for (int i = 0; i < n; i++) {
    for (; loca < n; loca++) {
      if (a[loca] < b[i].first) break;
      stc.push(a[loca]);
    }
    c[b[i].second] = stc.top();
    stc.pop();
  }
  for (int i = 0; i < n; i++) printf("%d ", c[i]);
  printf("\n");
  return 0;
}
