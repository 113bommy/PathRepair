#include <bits/stdc++.h>
using namespace std;
map<long long, int> imp;
int main() {
  int h, q;
  scanf("%d %d", &h, &q);
  for (int i = 0; i < q; i++) {
    int k, d;
    long long l, r;
    scanf("%d %I64d %I64d %d", &k, &l, &r, &d);
    l <<= (h - k);
    r++;
    r <<= (h - k);
    if (d) {
      imp[1LL << (h - 1)]--;
      imp[l]++;
      imp[r]--;
      imp[1LL << h]++;
    } else {
      imp[l]--;
      imp[r]++;
    }
  }
  int sum = 0;
  bool on = false, allcover = true;
  sum = 0;
  on = false;
  long long last;
  long long ans = 0;
  bool b = false;
  imp[1LL << (h - 1)]++;
  imp[1LL << h]--;
  for (map<long long, int>::iterator it = imp.begin(); it != imp.end(); it++) {
    sum += it->second;
    allcover &= sum <= 0;
    if (!on && sum > 0) {
      on = true;
      last = it->first;
    } else if (on && sum <= 0) {
      if (ans || it->first - last > 1) {
        b = true;
        break;
      }
      ans = last;
      on = false;
    }
  }
  if (q == 0) {
    if (h == 1) {
      printf("1\n");
    } else {
      printf("Data not sufficient!\n");
    }
  } else if (allcover) {
    printf("Game cheated!\n");
  } else if (b) {
    printf("Data not sufficient!\n");
  } else {
    printf("%I64d\n", ans);
  }
  return 0;
}
