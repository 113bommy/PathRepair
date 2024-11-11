#include <bits/stdc++.h>
using namespace std;
struct S {
  int x;
  int p;
  int id;
} in[100005];
int n;
bool cmp(S a, S b) {
  if (a.p != b.p) return a.p < b.p;
  return a.id < b.id;
}
void pt() {
  cout << "__" << endl;
  for (int i = 0; i < n; i++) {
    cout << in[i].x << "," << in[i].p << endl;
  }
  cout << "__" << endl;
}
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) {
      cin >> in[i].x >> in[i].p;
      in[i].id = i;
    }
    sort(in, in + n, cmp);
    int flag = 1;
    int wish = 0;
    if (in[0].x)
      flag = 0;
    else {
      for (int i = 1; i < n; i++) {
        if (in[i].p != in[i - 1].p) wish = 0;
        if (in[i].x > wish) {
          flag = 0;
          break;
        } else {
          if (in[i].x == wish) wish++;
        }
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
