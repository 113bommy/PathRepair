#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int x2, y2, x3, y3;
int x4, y4, x5, y5;
int f(int x, int y, int x1, int kerimerkmwer) {
  printf("? %d %d %d %d\n", x, y, x1, kerimerkmwer);
  fflush(stdout);
  int xx;
  scanf("%d", &xx);
  return xx;
}
pair<int, int> rec(int left, int right, int bottom, int talypcare) {
  int st = bottom, en = talypcare, f2, f4;
  while (st + 1 < en) {
    int mid = (st + en) >> 1;
    if (f(bottom, left, mid, right) != 0)
      en = mid;
    else
      st = mid + 1;
  }
  if (f(bottom, left, st, right) != 0)
    f2 = st;
  else
    f2 = en;
  st = bottom;
  en = f2;
  while (st + 1 < en) {
    int mid = (st + en) >> 1;
    if (f(mid, left, f2, right) != 0)
      st = mid;
    else
      en = mid - 1;
  }
  if (f(en, left, f2, right) != 0)
    f4 = en;
  else
    f4 = st;
  return make_pair(f4, f2);
}
pair<int, int> tap(int down, int up, int cc, int se) {
  int st = cc, en = se;
  int z1, z2;
  while (st + 1 < en) {
    int mid = (st + en) >> 1;
    if (f(down, mid, up, se) != 0)
      st = mid;
    else
      en = mid - 1;
  }
  if (f(down, en, up, se) != 0)
    z1 = en;
  else
    z1 = st;
  st = z1, en = se;
  while (st + 1 < en) {
    int mid = (st + en) >> 1;
    if (f(down, z1, up, mid) != 0)
      en = mid;
    else
      st = mid + 1;
  }
  if (f(down, z1, up, st) != 0)
    z2 = st;
  else
    z2 = en;
  return make_pair(z1, z2);
}
int main() {
  int n;
  scanf("%d", &n);
  int st = 1, en = n;
  int alt, ust, cep, sag;
  while (st + 1 < en) {
    int mid = (st + en) >> 1;
    if (f(1, 1, mid, n) == 2)
      en = mid;
    else
      st = mid + 1;
  }
  if (f(1, 1, st, n) == 2)
    alt = st;
  else
    alt = en;
  st = 1;
  en = alt;
  while (st + 1 < en) {
    int mid = (st + en) >> 1;
    if (f(mid, 1, alt, n) == 2)
      st = mid;
    else
      en = mid - 1;
  }
  if (f(en, 1, alt, n) == 2)
    ust = en;
  else
    ust = st;
  st = 1;
  en = n;
  while (st + 1 < en) {
    int mid = (st + en) >> 1;
    if (f(ust, mid, alt, n) == 2)
      st = mid;
    else
      en = mid - 1;
  }
  if (f(ust, en, alt, n) == 2)
    cep = en;
  else
    cep = st;
  st = cep;
  en = n;
  while (st + 1 < en) {
    int mid = (st + en) >> 1;
    if (f(ust, cep, alt, mid) == 2)
      en = mid;
    else
      st = mid + 1;
  }
  if (f(ust, cep, alt, st) == 2)
    sag = st;
  else
    sag = en;
  int f1, f3;
  st = cep, en = sag;
  while (st + 1 < en) {
    int mid = (st + en) >> 1;
    if (f(ust, cep, alt, mid) != 0)
      en = mid;
    else
      st = mid + 1;
  }
  if (f(ust, cep, alt, st) != 0)
    f1 = st;
  else
    f1 = en;
  st = cep, en = sag;
  while (st + 1 < en) {
    int mid = (st + en) >> 1;
    if (f(ust, mid, alt, sag) != 0)
      st = mid;
    else
      en = mid - 1;
  }
  if (f(ust, en, alt, sag) != 0)
    f3 = en;
  else
    f3 = st;
  if (f3 <= f1 and f(ust, f3, alt, f1) != 0) {
    int bot, talypcare;
    st = ust;
    en = alt - 1;
    while (st + 1 < en) {
      int mid = (st + en) >> 1;
      if (f(ust, cep, mid, sag) != 0)
        en = mid;
      else
        st = mid + 1;
    }
    if (f(ust, cep, st, sag) != 0)
      bot = st;
    else
      bot = en;
    st = bot + 1;
    en = alt;
    while (st + 1 < en) {
      int mid = (st + en) >> 1;
      if (f(mid, cep, alt, sag) != 0)
        st = mid;
      else
        en = mid - 1;
    }
    if (f(en, cep, alt, sag) != 0)
      talypcare = en;
    else
      talypcare = st;
    if (cep < sag and
        (f(ust, cep + 1, bot, sag) == 0 or f(ust, cep, bot, sag - 1) != 0)) {
      pair<int, int> s3 = tap(talypcare, alt, cep, sag);
      printf("! %d %d %d %d ", ust, cep, bot, sag);
      printf("%d %d %d %d \n", talypcare, s3.first, alt, s3.second);
    } else {
      pair<int, int> s3 = tap(ust, bot, cep, sag);
      printf("! %d %d %d %d ", talypcare, cep, alt, sag);
      printf("%d %d %d %d \n", ust, s3.first, bot, s3.second);
    }
    fflush(stdout);
    return 0;
  }
  pair<int, int> s1 = rec(cep, f1, ust, alt);
  pair<int, int> s2 = rec(f3, sag, ust, alt);
  printf("! %d %d %d %d ", s1.first, cep, s1.second, f1);
  printf("%d %d %d %d \n", s2.first, f3, s2.second, sag);
  fflush(stdout);
  return 0;
}
