#include <bits/stdc++.h>
using namespace std;
int n;
int f[1000][1000];
bool cp(int n) {
  double nn = double(n);
  int x = sqrt(nn);
  if (x * x == n)
    return true;
  else
    return false;
}
bool find(int d, int k) {
  if (d == n) {
    int temp = 0;
    for (int i = 0; i < n; i++) temp += f[n][i] * f[n][i];
    return cp(temp);
  }
  for (; k <= 4; k++) {
    f[n][d] = k;
    if (find(d + 1, k)) return true;
  }
  return false;
}
void work() {
  if (!find(0, 1)) puts("");
}
int main() {
  for (int i = 0; i <= 100; i++) {
    n = i;
    work();
  }
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << f[n][i] * f[m][j] << " ";
    }
    cout << endl;
  }
}
