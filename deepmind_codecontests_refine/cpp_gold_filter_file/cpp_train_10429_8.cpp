#include <bits/stdc++.h>
using namespace std;
int read(int &x) { return scanf("%d", &x); }
int read(int &x, int &y) { return scanf("%d%d", &x, &y); }
int read(int &x, int &y, int &z) { return scanf("%d%d%d", &x, &y, &z); }
int read(long long &x) { return scanf("%lld", &x); }
int read(long long &x, long long &y) { return scanf("%lld%lld", &x, &y); }
int read(double &x) { return scanf("%lf", &x); }
char buff[2000010];
int read(string &s) {
  int r = scanf("%s", buff);
  s = buff;
  return r;
}
int main() {
  vector<int> PHI(1000002);
  for (int i = 1; i < PHI.size(); ++i) {
    PHI[i] = i;
  }
  for (int i = 2; i < PHI.size(); ++i) {
    if (PHI[i] == i) {
      for (int j = i; j < PHI.size(); j += i) {
        PHI[j] = PHI[j] / i * (i - 1);
      }
    }
  }
  int N, K;
  read(N, K);
  if (K == 1) {
    cout << 3 << endl;
    return 0;
  }
  sort(PHI.begin() + 3, PHI.begin() + N + 1);
  cout << accumulate(PHI.begin() + 3, PHI.begin() + 3 + K, 2LL) << endl;
}
