#include <bits/stdc++.h>
using namespace std;
int prices[200000];
int main() {
  int allCount, price, count, badDays, min;
  cin >> allCount;
  for (int t = 0; t < allCount; t++) {
    cin >> count;
    badDays = 0;
    for (int i = 1; i <= count; ++i) {
      cin >> prices[i];
    }
    min = INT_MAX;
    for (int i = count; i > 0; --i) {
      if (prices[i] < min) {
        min = prices[i];
      } else {
        badDays++;
      }
    }
    cout << badDays << endl;
  }
  return 0;
}
