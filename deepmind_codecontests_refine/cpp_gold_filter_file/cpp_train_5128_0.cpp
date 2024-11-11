#include <bits/stdc++.h>
using namespace std;
int K, N;
int a[200000];
bool jo(int akt, bool stim) {
  int ki = 0;
  for (int i = 0; i < N; i++) {
    if (!stim) {
      ki++;
      stim = !stim;
    } else {
      if (akt >= a[i]) {
        ki++;
        stim = !stim;
      }
    }
  }
  return ki >= K;
}
int keres(int k, int v) {
  int kozep;
  while (k <= v) {
    kozep = (k + v) / 2;
    if (jo(kozep, true) || jo(kozep, false)) {
      v = kozep - 1;
    } else {
      k = kozep + 1;
    }
  }
  return k;
}
int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  cout << keres(1, 1e9) << '\n';
}
