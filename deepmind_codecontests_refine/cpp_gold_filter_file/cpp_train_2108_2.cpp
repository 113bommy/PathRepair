#include <bits/stdc++.h>
using namespace std;
void problem() {
  long long n;
  scanf("%lld", &n);
  long long curmas = 1, curbac = 1;
  int cm = 1, cb = 1, d = 0;
  vector<int> numsplit;
  if (n == 2) {
    printf("%d\n%d\n", 1, 0);
    return;
  }
  while (cm + cb * 6 < n) {
    d++;
    numsplit.push_back(cb);
    cb *= 2;
    cm += cb;
  }
  int r = n - cm;
  if (cb <= r && r <= cb * 2) {
    d += 1;
    numsplit.push_back(r - cb);
  } else if (r < cb * 3) {
    d += 2;
    numsplit.push_back(0);
    r -= cb;
    numsplit.push_back(r - cb);
  } else if (r < cb * 4) {
    d += 2;
    numsplit.push_back(cb / 2);
    cb += cb / 2;
    r -= cb;
    numsplit.push_back(r - cb);
  } else {
    d += 2;
    numsplit.push_back(cb);
    cb *= 2;
    r -= cb;
    numsplit.push_back(r - cb);
  }
  printf("%d\n", d);
  for (int i = 0; i < d; ++i) {
    printf("%d ", numsplit[i]);
  }
  printf("\n");
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    problem();
  }
  return 0;
}
