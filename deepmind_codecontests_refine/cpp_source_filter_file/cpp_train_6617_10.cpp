#include <bits/stdc++.h>
using namespace std;
int w[100005];
int main(int argc, const char* argv[]) {
  int i, x, temp, da, xiao;
  int renshu, n1, n2;
  cin >> renshu;
  cin >> n1;
  cin >> n2;
  for (i = 0; i < renshu; i++) {
    cin >> w[i];
  }
  sort(w, w + renshu);
  da = max(n1, n2);
  xiao = min(n1, n2);
  int s = 0, b = 0;
  for (i = renshu - 1; i > renshu - xiao - 1; i--) {
    s += w[i];
  }
  for (i = renshu - xiao - 1; i > renshu - xiao - da - 1; i--) {
    b += w[i];
  }
  double z = b * 1.000000 / da + s * 1.000000 / xiao;
  printf("%lf", z);
  return 0;
}
