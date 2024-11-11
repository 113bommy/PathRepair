#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, m;
  cin >> d >> m;
  vector<int> mon(m);
  for (int i = 0; i < m; i++) cin >> mon[i];
  int date = d;
  int cost = 0;
  for (int i = 0; i < m; i++) {
    if (date == d)
      ;
    else {
      cost += d - date;
    }
    date = mon[i];
  }
  cout << cost;
}
