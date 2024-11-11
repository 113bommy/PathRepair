#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
int n;
int cont;
double res[MAXN];
double num[MAXN];
bool Solve(double m) {
  cont = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (i < n && num[i] <= num[j] + m) i++;
    res[cont++] = min(num[j] + m, 1000000000.0);
    while (i < n && num[i] <= num[j] + m + m) i++;
    i--;
  }
  return cont <= 3;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(6);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num, num + n);
  double ini = 0.0, fin = 1000000000.0;
  for (int i = 0; i < 60; i++) {
    double med = (ini + fin) / 2;
    if (!Solve(med))
      ini = med + 1e-7;
    else
      fin = med;
  }
  for (int i = cont; i < n; i++) res[i] = res[i - 1];
  cout << ini << '\n';
  for (int i = 0; i < 3; i++) cout << res[i] << " ";
  cout << '\n';
  return 0;
}
