#include <bits/stdc++.h>
using namespace std;
int l[10];
int b[10];
int n, A;
double maxprob;
void findit(int pos, int k) {
  if (pos == n) {
    double totprob = 0;
    for (int m = 0; m < (1 << n); m++) {
      int ct = 0;
      double p = 1.0;
      int B = 0;
      for (int i = 0; i < n; i++) {
        if ((m >> i) & 1) {
          p = p * (1 - (double)l[i] / 100.0);
          B += b[i];
        } else {
          p = p * (double)l[i] / 100.0;
          ct++;
        }
      }
      if (2 * ct <= n) {
        p *= ((double)A) / (A + B + 0.0);
      }
      totprob += p;
    }
    maxprob = max(maxprob, totprob);
    return;
  }
  if (k > 0 && l[pos] < 100) {
    l[pos] += 10;
    findit(pos, k - 1);
    l[pos] -= 10;
  }
  findit(pos + 1, k);
}
int main() {
  int k;
  cin >> n >> k >> A;
  for (int i = 0; i < n; i++) {
    cin >> b[i] >> l[i];
  }
  maxprob = 0.0;
  findit(0, k);
  printf("%1.10f\n", maxprob);
}
