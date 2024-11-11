#include <bits/stdc++.h>
using namespace std;
int sum;
int m;
int l, r, mid, ans;
int pack[100005];
int man[100005];
int start1, start2;
bool check(int x) {
  int jsq = 0;
  int head = 1, tail = 1;
  while (jsq != start1 && head <= start2) {
    int F = pack[tail];
    if (pack[tail] < man[head]) {
      if (man[head] - pack[tail] > x) return 0;
      for (int j = tail;; j++) {
        if (man[head] < pack[j]) break;
        jsq++;
        tail++;
      }
      if (x > (man[head] - F)) {
        int xx = max(man[head] + x - 2 * (man[head] - F),
                     man[head] + (x - (man[head] - F)) / 2);
        for (int i = tail;; i++) {
          if (pack[i] > xx) {
            break;
          }
          jsq++;
          tail++;
        }
      }
    } else {
      int xx = man[head] + x;
      for (int i = tail;; i++) {
        if (pack[i] > xx) break;
        tail++;
        jsq++;
      }
    }
    head++;
  }
  if (jsq == start1) return 1;
  return 0;
}
int main() {
  start1 = 0;
  start2 = 0;
  cin >> m;
  getchar();
  char a;
  for (int i = 1; i <= m; i++) {
    scanf("%c", &a);
    if (a == '*') start1++, pack[start1] = i;
    if (a == 'P') start2++, man[start2] = i;
  }
  pack[start1 + 1] = 0x3f3f3f3f;
  man[start2 + 1] = 0x3f3f3f3f;
  l = 1;
  r = 2 * m;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans;
  return 0;
}
