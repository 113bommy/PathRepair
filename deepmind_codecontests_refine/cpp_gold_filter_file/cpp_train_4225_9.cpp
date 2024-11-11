#include <bits/stdc++.h>
using namespace std;
int cards[222222];
pair<int, int> cards2[222222];
int big = 1000000002;
map<int, int> mp;
char mark[222222];
int m;
int allocard1() {
  static int last = -1;
  last += 2;
  while (true) {
    if (mp.find(last) == mp.end()) {
      break;
    }
    last += 2;
  }
  if (last > m) {
    printf("-1");
    exit(0);
  }
  return last;
}
int allocard2() {
  static int last = 0;
  last += 2;
  while (true) {
    if (mp.find(last) == mp.end()) {
      break;
    }
    last += 2;
  }
  if (last > m) {
    printf("-1");
    exit(0);
  }
  return last;
}
int main() {
  int n;
  scanf("%i%i", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%i", &cards[i]);
  }
  int mc = m / 2;
  int mn = m - mc;
  int bc = 0;
  int bn = 0;
  int oc = 0;
  int on = 0;
  for (int i = 0; i < n; i++) {
    if (cards[i] & 1) {
      on++;
    } else {
      oc++;
    }
    if (mp[cards[i]] == 1) {
      if (cards[i] & 1) {
        bn++;
      } else {
        bc++;
      }
      mark[i] = 1;
    } else {
      mp[cards[i]] = 1;
      mark[i] = 0;
    }
    cards2[i] = make_pair(cards[i], i);
  }
  sort(cards2, cards2 + n);
  int killc = 0;
  int killn = 0;
  if (n / 2 < oc - bc) {
    killc = oc - bc - n / 2;
  }
  if (n / 2 < on - bn) {
    killn = on - bn - n / 2;
  }
  int lb = 2;
  int kill = 0;
  if (killc > 0) {
    lb = 0;
    kill = killc;
  } else if (killn > 0) {
    lb = 1;
    kill = killn;
  }
  int add = 0;
  for (int i = 0, j = 0; i < n && j < kill; i++) {
    if ((cards2[i].first & 1) == lb && !mark[cards2[i].second]) {
      mark[cards2[i].second] = 1;
      add++;
      j++;
    }
  }
  if (killc > 0) {
    bc += add;
  } else if (killn > 0) {
    bn += add;
  }
  int ans = bc + bn;
  mp.clear();
  int gc = 0;
  int gn = 0;
  for (int i = 0; i < n; i++) {
    if (!mark[i]) {
      mp[cards[i]] = 1;
      if (cards[i] & 1) {
        gn++;
      } else {
        gc++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (mark[i]) {
      if (gn < n / 2) {
        cards[i] = allocard1();
        gn++;
      } else {
        cards[i] = allocard2();
      }
    }
  }
  printf("%i\n", ans);
  for (int i = 0; i < n; i++) {
    printf("%i ", cards[i]);
  }
}
