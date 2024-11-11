#include <bits/stdc++.h>
using namespace std;
struct state {
  int a, b, c, base, idx;
  bool operator<(const state &other) const {
    if (a == other.a) {
      if (b == other.b) {
        return c < other.c;
      }
      return b < other.b;
    }
    return a < other.a;
  }
};
set<state> first, second;
state one[111], two[111];
int main() {
  int n;
  scanf("%d\n", &n);
  for (auto(i) = (0); (i) < (n / 2); (i)++) {
    scanf("%d %d %d\n", &one[i].a, &one[i].b, &one[i].c);
  }
  for (auto(i) = (n / 2); (i) < (n); (i)++) {
    scanf("%d %d %d\n", &two[i - n / 2].a, &two[i - n / 2].b,
          &two[i - n / 2].c);
  }
  int ff = 1;
  for (auto(i) = (0); (i) < (n / 2); (i)++) ff *= 3;
  for (auto(i) = (0); (i) < (ff); (i)++) {
    state kek;
    kek.a = kek.b = kek.c = 0;
    int cop = i;
    int asdf[15];
    ;
    for (auto(j) = (0); (j) < (15); (j)++) {
      asdf[j] = cop % 3;
      if (j < 2)
        ;
      cop /= 3;
    };
    int base = 0;
    kek.idx = i;
    for (auto(j) = (0); (j) < (n / 2); (j)++) {
      kek.a += one[j].a;
      kek.b += one[j].b;
      kek.c += one[j].c;
      if (asdf[j] == 0) kek.a -= one[j].a;
      if (asdf[j] == 1) kek.b -= one[j].b;
      if (asdf[j] == 2) kek.c -= one[j].c;
    }
    base += kek.a;
    kek.b -= kek.a;
    kek.c -= kek.a;
    kek.a = 0;
    kek.base = base;
    first.insert(kek);
    ;
  };
  ff = 1;
  for (auto(i) = (n / 2); (i) < (n); (i)++) ff *= 3;
  for (auto(i) = (0); (i) < (ff); (i)++) {
    state kek;
    kek.a = kek.b = kek.c = 0;
    int cop = i;
    int asdf[15];
    ;
    for (auto(j) = (0); (j) < (15); (j)++) {
      asdf[j] = cop % 3;
      if (j < 2)
        ;
      cop /= 3;
    };
    int base = 0;
    kek.idx = i;
    for (auto(j) = (n / 2); (j) < (n); (j)++) {
      kek.a += two[j - n / 2].a;
      kek.b += two[j - n / 2].b;
      kek.c += two[j - n / 2].c;
      if (asdf[j - n / 2] == 0) kek.a -= two[j - n / 2].a;
      if (asdf[j - n / 2] == 1) kek.b -= two[j - n / 2].b;
      if (asdf[j - n / 2] == 2) kek.c -= two[j - n / 2].c;
    }
    base += kek.a;
    kek.b -= kek.a;
    kek.c -= kek.a;
    kek.a = 0;
    kek.base = base;
    second.insert(kek);
    ;
  }
  int found = -111111111;
  int goodidx1 = 0, goodidx2;
  for (state kek : first) {
    state asdf = kek;
    asdf.a = 0;
    asdf.b *= -1;
    asdf.c *= -1;
    auto it = second.find(asdf);
    while (it != second.end() && it->a == asdf.a && it->b == asdf.b &&
           it->c == asdf.c) {
      if (it->base + asdf.base > found) {
        ;
        found = it->base + asdf.base;
        goodidx1 = asdf.idx;
        goodidx2 = it->idx;
      }
      it++;
    }
  }
  if (found == -111111111) {
    puts("Impossible");
    return 0;
  }
  ff = 1;
  int ar[15];
  for (auto(i) = (0); (i) < ((n / 2)); (i)++) {
    ff *= 3;
  }
  for (auto(i) = (0); (i) < (15); (i)++) {
    ar[i] = goodidx1 % 3;
    goodidx1 /= 3;
  }
  for (auto(i) = (0); (i) < (n / 2); (i)++) {
    if (ar[i] == 0) {
      puts("MW");
    }
    if (ar[i] == 1) {
      puts("LW");
    }
    if (ar[i] == 2) {
      puts("ML");
    }
  }
  ff = 1;
  for (auto(i) = (n / 2); (i) < (n); (i)++) {
    ff *= 3;
  }
  for (auto(i) = (0); (i) < (15); (i)++) {
    ar[i] = goodidx2 % 3;
    goodidx2 /= 3;
  }
  for (auto(i) = (n / 2); (i) < (n); (i)++) {
    if (ar[i - n / 2] == 0) {
      puts("MW");
    }
    if (ar[i - n / 2] == 1) {
      puts("LW");
    }
    if (ar[i - n / 2] == 2) {
      puts("ML");
    }
  }
  return 0;
}
