#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m, a, b, c, i, j, res, curr, temp;
  cin >> n >> m;
  vector<long> verArr(n);
  vector<long> horArr;
  for (i = 0; i < n; i++) {
    cin >> verArr[i];
  }
  for (i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (a == 1) horArr.push_back(b);
  }
  res = horArr.size();
  verArr.push_back(1e9);
  sort(horArr.begin(), horArr.end());
  sort(verArr.begin(), verArr.end());
  curr = 0;
  j = 0;
  temp = horArr.size();
  for (i = 0; i < verArr.size(); i++) {
    curr = 0;
    while (j < temp && horArr[j] < verArr[i]) {
      j++;
      curr++;
    }
    res = min(i + temp - (curr), res);
  }
  cout << res;
}
