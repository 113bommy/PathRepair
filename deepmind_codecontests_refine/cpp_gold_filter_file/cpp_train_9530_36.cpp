#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int yes = 0;
  string name[n];
  int before[n], after[n];
  for (int i = 0; i < n; ++i) {
    cin >> name[i];
    if (name[i].size() > 10) return -1;
    cin >> before[i];
    cin >> after[i];
  }
  for (int i = 0; i < n; ++i) {
    if (before[i] >= 2400 && before[i] < after[i]) yes++;
  }
  if (yes > 0)
    cout << "YES";
  else
    cout << "NO";
}
