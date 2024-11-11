#include <bits/stdc++.h>
using namespace std;
struct node {
  int start;
  int number;
  int endday;
} fru[10000];
bool cmp(node a, node b) {
  if (a.start < b.start) return true;
  if (a.start > b.start) return false;
  if (a.start == b.start) {
    if (a.number > b.number)
      return true;
    else
      return false;
  }
}
int main() {
  int n, m, sum, limit, day, now;
  while (cin >> n >> m) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &fru[i].start, &fru[i].number);
      fru[i].endday = fru[i].start + 1;
    }
    sort(fru, fru + n, cmp);
    int sday = fru[0].start, eday = fru[n - 1].endday;
    day = sday;
    now = 0;
    limit = m;
    while (day <= eday && now < n) {
      if (fru[n - 1].endday < day) break;
      if (day < fru[now].start) {
        day++;
        limit = m;
        continue;
      }
      if (day > fru[now].endday) {
        now++;
        continue;
      }
      if (day >= fru[now].start && day <= fru[now].endday) {
        if (fru[now].number > limit) {
          sum += limit;
          fru[now].number -= limit;
          limit = m;
          day++;
          continue;
        }
        if (fru[now].number == limit) {
          sum += limit;
          fru[now].number -= limit;
          limit = m;
          now++;
          day++;
          continue;
        }
        if (fru[now].number < limit) {
          sum += fru[now].number;
          limit -= fru[now].number;
          fru[now].number = 0;
          now++;
        }
      } else
        now++;
    }
    cout << sum << endl;
  }
  return 0;
}
