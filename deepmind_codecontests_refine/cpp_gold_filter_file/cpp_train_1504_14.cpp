#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d\n", &n);
  int left = -1000000001;
  int right = 1000000001;
  string q;
  int num;
  char ans;
  for (int i = 0; i < n; ++i) {
    cin >> q >> num >> ans;
    cin.get();
    if (q == ">") {
      if (ans == 'Y') {
        left = max(left, num + 1);
      } else {
        right = min(right, num);
      }
    } else if (q == "<") {
      if (ans == 'Y') {
        right = min(right, num - 1);
      } else {
        left = max(left, num);
      }
    } else if (q == ">=") {
      if (ans == 'Y') {
        left = max(left, num);
      } else {
        right = min(right, num - 1);
      }
    } else if (q == "<=") {
      if (ans == 'Y') {
        right = min(right, num);
      } else {
        left = max(left, num + 1);
      }
    }
  }
  if (right < left)
    cout << "Impossible" << endl;
  else
    cout << left << endl;
  return 0;
}
