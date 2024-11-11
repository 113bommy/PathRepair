#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mini = 10000, p, cost = 0;
  cin >> n;
  int x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cost = 0;
    for (int j = 0; j < x[i]; j++) {
      cin >> p;
      cost += (p * 5);
    }
    cost += (x[i] * 15);
    mini = min(cost, mini);
  }
  cout << mini;
}
