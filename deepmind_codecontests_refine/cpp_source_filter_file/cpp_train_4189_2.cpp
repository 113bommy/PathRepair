#include <bits/stdc++.h>
using namespace std;
long long t, n, val[200005];
char a[200005];
void max_lis() {
  long long prev = 0, prev_inc = 0;
  bool dec = false;
  unordered_map<long long, list<long long> > level;
  long long min_level = 1000000009, max_level = -1000000009;
  for (int i = 0; i < n; i++) {
    if (dec) {
      level[prev - 1];
      level[--prev].push_back(i);
      min_level = min(min_level, prev);
      max_level = max(max_level, prev);
    } else {
      level[prev_inc + 1];
      level[++prev_inc].push_back(i);
      min_level = min(min_level, prev_inc);
      max_level = max(max_level, prev_inc);
      prev = prev_inc;
    }
    if (a[i] == '>')
      dec = true;
    else
      dec = false;
  }
  long long counter = 1;
  for (long long lv = min_level; lv <= max_level; lv++) {
    for (long long id : level[lv]) {
      val[id] = counter++;
    }
  }
  for (int i = 0; i < n; i++) printf("%lld ", val[i]);
  printf("\n");
}
void min_lis() {
  long long prev = 0, prev_inc = 0;
  bool inc = true;
  unordered_map<long long, list<long long> > level;
  long long min_level = 1000000009, max_level = -1000000009;
  for (int i = 0; i < n; i++) {
    if (inc) {
      level[prev_inc + 1];
      level[++prev_inc].push_front(i);
      min_level = min(min_level, prev_inc);
      max_level = max(max_level, prev_inc);
      prev = prev_inc;
    } else {
      level[prev - 1];
      level[--prev].push_front(i);
      min_level = min(min_level, prev);
      max_level = max(max_level, prev);
    }
    if (a[i] == '>')
      inc = false, prev_inc = prev = 0;
    else
      inc = true;
  }
  long long counter = 1;
  for (long long lv = min_level; lv <= max_level; lv++) {
    for (long long id : level[lv]) {
      val[id] = counter++;
    }
  }
  for (int i = 0; i < n; i++) printf("%lld ", val[i]);
  printf("\n");
}
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    scanf("%s", a);
    max_lis();
    min_lis();
  }
  return 0;
}
