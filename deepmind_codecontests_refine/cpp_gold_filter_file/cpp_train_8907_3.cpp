#include <bits/stdc++.h>
using namespace std;
vector<int> bla;
set<int> fats;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void mult(long long int x) {
  vector<int> add;
  for (set<int>::iterator it = fats.begin(), end = fats.end(); it != end; ++it)
    add.push_back(*it * x);
  for (int i = 0, s = add.size(); i < s; ++i) fats.insert(add[i]);
}
void fat(long long int x) {
  long long int i, c, raiz;
  fats.insert(1);
  c = x;
  while (c % 2 == 0) {
    mult(2);
    fats.insert(2);
    c /= 2;
  }
  i = 3;
  raiz = sqrt(c) + 2;
  while (i < raiz && c > 1) {
    while (c % i == 0) {
      mult(i);
      fats.insert(i);
      c /= i;
    }
    i += 2;
    raiz = sqrt(c) + 2;
  }
  if (c > 1) {
    mult(c);
    fats.insert(c);
  }
  for (set<int>::iterator it = fats.begin(); it != fats.end(); ++it)
    bla.push_back(*it);
}
int main() {
  int a, b, n, c, d;
  scanf("%d%d%d", &a, &b, &n);
  int g = gcd(a, b);
  fat(g);
  bla.push_back(g);
  while (n--) {
    scanf("%d%d", &c, &d);
    vector<int>::iterator low = lower_bound(bla.begin(), bla.end(), c);
    vector<int>::iterator high = lower_bound(bla.begin(), bla.end(), d);
    if (low == bla.end()) {
      printf("-1\n");
      continue;
    } else if (high == bla.end())
      --high;
    else if (*high != d)
      --high;
    if (high >= low)
      printf("%d\n", *high);
    else
      printf("-1\n");
  }
  return 0;
}
