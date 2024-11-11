#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  int low, high;
  int nowresult, nowmoney;
  vector<int> results(n + 1);
  vector<int> money(n + 1);
  for (int i = 0; i < n + 1; i++) {
    results[i] = 1001;
    money[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    cin >> low;
    cin >> high;
    cin >> nowresult;
    cin >> nowmoney;
    for (int j = low; j < high + 1; j++) {
      if (nowresult < results[j]) {
        money[j] = nowmoney;
        results[j] = nowresult;
      }
    }
  }
  int finsum = 0;
  for (int i = 0; i < n + 1; i++) {
    if (money[i] != 1001) {
      finsum += money[i];
    }
  }
  cout << finsum;
  return 0;
}
