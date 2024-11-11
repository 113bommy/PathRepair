#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  int n;
  cin >> n;
  double suma = 0;
  vector<double> arr;
  for (int i = 0; i < n; i++) {
    double t;
    cin >> t;
    suma += t;
    arr.push_back(t);
  }
  sort(arr.begin(), arr.end());
  double p = round(suma / n * 1.0);
  if (p == 5) {
    cout << 0;
    return 0;
  }
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    suma -= arr[0];
    suma += 5;
    p = round(suma / n * 1.0);
    if (p == 5) {
      cout << cnt;
      return 0;
    }
    cnt++;
  }
}
