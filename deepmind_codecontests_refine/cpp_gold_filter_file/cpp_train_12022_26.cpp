#include <bits/stdc++.h>
using namespace std;
const int MAXR = 10005;
const int MAXN = 6;
struct interval {
  int l, r;
  double d;
};
double prob[MAXR];
interval A[MAXN];
int getOnes(int x) {
  int res = 0;
  while (x != 0) {
    res += x % 2;
    x /= 2;
  }
  return res;
}
double probWin(int person, int i) {
  if (i >= A[person].r) return 0;
  if (i < A[person].l) return 1;
  return ((double)(A[person].r - i)) / A[person].d;
}
double probLose(int person, int i) {
  if (i > A[person].r) return 1;
  if (i <= A[person].l) return 0;
  return ((double)(i - A[person].l)) / A[person].d;
}
double probPercise(int person, int i) {
  if (i > A[person].r) return 0;
  if (i < A[person].l) return 0;
  return (double)(1) / A[person].d;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i].l >> A[i].r;
    A[i].d = (double)(A[i].r - A[i].l + 1);
  }
  double ans = 0;
  for (int i = 1; i < MAXR; i++) {
    prob[i] = 0;
    for (int winer = 1; winer <= n; winer++) {
      for (int mask = 1; mask < (1 << n); mask++) {
        int Mask = mask;
        double p = 1;
        bool wasOne = false;
        int ones = getOnes(Mask);
        for (int person = 1; person <= n; person++) {
          if (person == winer) {
            if (Mask % 2 == 0)
              p *= probWin(person, i);
            else {
              if (ones > 1 && !wasOne)
                p *= probPercise(person, i);
              else
                p = 0;
            }
          } else {
            if (Mask % 2 == 0) {
              p *= probLose(person, i);
            } else {
              p *= probPercise(person, i);
            }
          }
          if (Mask % 2 == 1) wasOne = true;
          Mask /= 2;
        }
        prob[i] += p;
      }
    }
    ans += prob[i] * double(i);
  }
  cout << setprecision(12) << fixed << ans << endl;
  return 0;
}
