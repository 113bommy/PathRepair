#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n;
  int b = n;
  vector<int> v(1e5, 0);
  while (n--) {
    cin >> a;
    v[a]++;
  }
  int max = *max_element(v.begin(), v.end());
  if (b % 2 == 0 && max > b / 2) {
    cout << "NO";
  } else if (b % 2 != 0 && max > b + 1 / 2) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
