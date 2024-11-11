#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
const int maxn = (int)3e5 + 10;
struct point {
  int ed[2];
  int cnt;
  point() {
    ed[0] = ed[1] = -1;
    cnt = 0;
  }
};
point mas[maxn * 20];
int posit = 0;
int my_new() { return posit++; }
void add(int t, int x, int pos) {
  mas[t].cnt++;
  if (pos == -1) {
    return;
  }
  int b = (x >> pos) & 1;
  if (mas[t].ed[b] == -1) {
    mas[t].ed[b] = my_new();
  }
  add(mas[t].ed[b], x, pos - 1);
}
int a[maxn];
int go(int t, int x, int pos) {
  mas[t].cnt--;
  if (pos == -1) {
    return 0;
  }
  int b = (x >> pos) & 1;
  if (mas[t].ed[b] != -1 && mas[mas[t].ed[b]].cnt != 0) {
    int ans = go(mas[t].ed[b], x, pos - 1);
    if (b == 1) {
      ans += (1 << pos);
    }
    return ans;
  }
  b ^= 1;
  int ans = go(mas[t].ed[b], x, pos - 1);
  if (b == 1) {
    ans += (1 << pos);
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int t = my_new();
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    add(t, x, 29);
  }
  for (int i = 0; i < a[i]; i++) {
    int z = go(t, a[i], 29);
    printf("%d ", z ^ a[i]);
  }
}
