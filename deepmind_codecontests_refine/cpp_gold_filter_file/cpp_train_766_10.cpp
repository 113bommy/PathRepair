#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int cnt = 0;
  int x = 1;
  bool flag = false;
  vector<int> storer(n);
  for (int i = 0; i < n; i++) {
    cin >> storer[i];
  }
  sort(storer.begin(), storer.end());
  for (int i = 1; i < n; i++) {
    if (storer[i] < 0) {
      cnt++;
    } else {
      break;
    }
  }
  cout << 1 << " " << storer[0] << endl;
  if (cnt % 2 != 0) {
    x = x + 1;
    flag = true;
  }
  if (flag == true) {
    cout << n - 3 << " ";
  }
  if (flag == false) {
    cout << n - 2 << " ";
  }
  for (int i = x; i < n; i++) {
    if (storer[i] != 0) {
      cout << storer[i] << " ";
    }
  }
  cout << endl;
  if (flag == true) {
    cout << 2 << " " << 0 << " " << storer[1];
  }
  if (flag == false) {
    cout << 1 << " " << 0;
  }
  return 0;
}
