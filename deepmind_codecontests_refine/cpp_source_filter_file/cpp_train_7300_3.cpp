#include <bits/stdc++.h>
using namespace std;
void dummy() {}
int n;
long long data[500];
long long gr[500];
void fill(long long v) {
  memset(gr, 0, sizeof(gr));
  int i = 0;
  while (v) {
    while (data[i] > v) i++;
    long long c = v / data[i];
    gr[i] += c;
    v %= data[i];
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> data[i];
  long long rbad = -1;
  for (int i = 1; i < n; i++)
    for (int j = i; j < n; j++) {
      fill(data[i - 1] - 1);
      long long opt = 0, bad = data[j];
      for (int k = 0; k <= j; k++) {
        opt += gr[k];
        bad += (long long)data[k] * gr[k];
      }
      fill(bad);
      long long greed = 0;
      for (int k = 0; k < n; k++) greed += gr[k];
      if (greed > opt)
        if (rbad == -1 || rbad > bad) rbad = bad;
    }
  cout << rbad << endl;
  return 0;
}
