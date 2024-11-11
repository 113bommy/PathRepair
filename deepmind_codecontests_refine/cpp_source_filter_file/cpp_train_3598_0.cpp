#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  char op;
  scanf("%d", &q);
  while (q--) {
    set<int> mins, maxs;
    scanf("%d", &n);
    if (n == 1) {
      printf("! 1 1\n");
      fflush(stdout);
      continue;
    }
    for (int i = 1; i < n; i += 2) {
      if ((mins.count(i) || maxs.count(i)) &&
          (mins.count(i + 1) || maxs.count(i + 1)))
        continue;
      if (n % 2 && i == 1) {
        printf("? %d %d\n", n, n - 1);
        fflush(stdout);
        scanf(" %c", &op);
        if (op == '<') {
          mins.insert(n);
          maxs.insert(n - 1);
        } else {
          mins.insert(n - 1);
          maxs.insert(n);
        }
      }
      printf("? %d %d\n", i, i + 1);
      fflush(stdout);
      scanf(" %c", &op);
      if (op == '<') {
        if (!maxs.count(i)) mins.insert(i);
        if (!mins.count(i + 1)) maxs.insert(i + 1);
      } else {
        if (!maxs.count(i + 1)) mins.insert(i + 1);
        if (!mins.count(i)) maxs.insert(i);
      }
    }
    int i = 1;
    while (mins.size() > 1) {
      if (i >= mins.size()) i = 1;
      int a = i;
      auto it = mins.begin();
      while (i) {
        it++;
        i--;
      }
      auto it2 = it;
      it--;
      i = a + 1;
      printf("? %d %d\n", *it, *it2);
      fflush(stdout);
      scanf(" %c", &op);
      if (op == '<') {
        if (maxs.count(*it)) maxs.erase(*it);
        mins.erase(*it2);
      } else {
        if (maxs.count(*it2)) maxs.erase(*it2);
        mins.erase(*it);
      }
    }
    i = 1;
    while (maxs.size() > 1) {
      if (i == maxs.size()) i = 1;
      int a = i;
      auto it = maxs.begin();
      while (i) {
        it++;
        i--;
      }
      auto it2 = it;
      it--;
      i = a + 1;
      printf("? %d %d\n", *it, *it2);
      fflush(stdout);
      scanf(" %c", &op);
      if (op == '>')
        maxs.erase(*it2);
      else
        maxs.erase(*it);
    }
    printf("! %d %d\n", *mins.begin(), *maxs.begin());
    fflush(stdout);
  }
  return 0;
}
