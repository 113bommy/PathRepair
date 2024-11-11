#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
double fRand(double fMin, double fMax) {
  double f = (double)rand() / RAND_MAX;
  return fMin + f * (fMax - fMin);
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
int n;
int main() {
  scanf("%d", &n);
  int cntSoft = 0, cntHard = 0;
  for (int i = (1); i <= (n); ++i) {
    string s;
    cin >> s >> s;
    if (s == "soft")
      ++cntSoft;
    else
      ++cntHard;
  }
  if (cntSoft > cntHard) swap(cntSoft, cntHard);
  for (int i = (1); i <= (n); ++i) {
    int cntBlack = (i * i + 1) / 2, cntWhite = (i * i - 1) / 2;
    if (cntBlack >= cntHard && cntWhite >= cntSoft) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
