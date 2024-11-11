#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char *argv[]) {
  int n = 0;
  double k = 0.0, days = 0.0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    double amount = 0.0;
    cin >> amount;
    amount = amount / k;
    amount = ceil(amount);
    days += amount;
  }
  days = days / 2.0;
  days = ceil(days);
  cout << days << endl;
  return 0;
}
