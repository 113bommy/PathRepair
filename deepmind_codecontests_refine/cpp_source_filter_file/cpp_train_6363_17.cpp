#include <bits/stdc++.h>
using namespace std;
struct S {
  int x, y;
} a[3];
bool cmp(S a, S b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
set<pair<int, int> > s;
int main() {
  int i;
  for (i = 0; i < 3; i++) cin >> a[i].x >> a[i].y;
  sort(a, a + 3, cmp);
  if (a[0].x == a[1].x) {
    for (i = a[0].y; i <= a[1].y; i++) s.insert(make_pair(a[0].x, i));
    if (a[2].y <= a[1].y && a[2].y >= a[0].y)
      for (i = a[0].x; i <= a[2].x; i++) s.insert(make_pair(i, a[2].y));
    else {
      for (i = a[1].x; i <= a[2].x; i++) s.insert(make_pair(i, a[1].y));
      if (a[2].y > a[1].y)
        for (i = a[1].y; i <= a[2].y; i++) s.insert(make_pair(a[2].x, i));
      else
        for (i = a[2].y; i <= a[0].y; i++) s.insert(make_pair(a[2].x, i));
    }
  } else if (a[1].x == a[2].x) {
    for (i = a[1].y; i <= a[2].y; i++) s.insert(make_pair(a[1].x, i));
    if (a[0].y <= a[2].y && a[0].y >= a[1].y)
      for (i = a[0].x; i <= a[1].x; i++) s.insert(make_pair(i, a[0].y));
    else {
      for (i = a[0].x; i <= a[1].x; i++) s.insert(make_pair(i, a[1].y));
      if (a[0].y > a[2].y)
        for (i = a[2].y; i <= a[0].y; i++) s.insert(make_pair(a[0].x, i));
      else
        for (i = a[0].y; i <= a[1].y; i++) s.insert(make_pair(a[0].x, i));
    }
  } else {
    for (i = a[0].x; i <= a[1].x; i++) s.insert(make_pair(i, a[0].y));
    if (a[0].y > a[1].y)
      for (i = a[1].y; i <= a[0].y; i++) s.insert(make_pair(a[1].x, i));
    else
      for (i = a[0].y; i <= a[1].y; i++) s.insert(make_pair(a[1].x, i));
    for (i = a[1].x; i <= a[2].x; i++) s.insert(make_pair(i, a[2].y));
    if (a[2].y < min(a[1].y, a[0].y))
      for (i = a[2].y; i <= min(a[1].y, a[0].y); i++)
        s.insert(make_pair(a[1].x, i));
    else if (a[2].y > max(a[1].y, a[0].y))
      for (i = max(a[1].y, a[0].y); i <= a[2].y; i++)
        s.insert(make_pair(a[1].x, i));
  }
  cout << s.size() << endl;
  for (set<pair<int, int> >::iterator it = s.begin(); it != s.end(); it++)
    cout << it->first << " " << it->second << endl;
}
