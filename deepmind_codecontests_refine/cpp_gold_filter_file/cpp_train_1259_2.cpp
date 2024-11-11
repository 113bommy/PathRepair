#include <bits/stdc++.h>
using namespace std;
void func(vector<char> v, int n) {
  int count = 0;
  for (int i = 0; i < n / 2; i++) {
    if ((int)v[i] == (int)v[n - i - 1]) {
      count++;
      continue;
    } else if ((int)v[i] == 97) {
      if ((int)v[n - i - 1] == 99) {
        count++;
        continue;
      } else {
        continue;
      }
    } else if ((int)v[i] == 122) {
      if ((int)v[n - i - 1] == 120) {
        count++;
        continue;
      } else {
        continue;
      }
    } else if (abs((int)v[i] - (int)v[n - i - 1]) == 2) {
      count++;
      continue;
    }
  }
  if (count == (n / 2)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<char> v;
    for (int i = 0; i < n; i++) {
      char l;
      cin >> l;
      v.push_back(l);
    }
    func(v, n);
  }
}
