#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  vector<long long> a(k);
  for (int h = 0; h < a.size(); h++) {
    cin >> a[h];
  };
  int gg = max_element(a.begin(), a.end()) - a.begin();
  gg--;
  for (int i = k - 1; i > gg; i--) {
    if (a[i] < a[i - 1]) {
      cout << "no";
      return 0;
    }
  }
  for (int i = 0; i < gg; i++) {
    if (a[i] > a[i + 1]) {
      cout << "no";
      return 0;
    }
  }
  cout << "YES";
}
