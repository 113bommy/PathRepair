#include <bits/stdc++.h>
using namespace std;
int qadr(int num) { return (num < 0 ? -num : num); }
int main() {
  int n, rcnt = 0, lcnt = 0;
  cin >> n;
  string command;
  cin >> command;
  for (int i = 0; i < n; i++) {
    if (command[i] == 'R') {
      rcnt++;
    }
  }
  lcnt = n - rcnt;
  cout << qadr(-lcnt - rcnt) + 1 << endl;
  return 0;
}
