#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    vector<int> array;
    int a;
    for (int j = 0; j < n; j++) {
      cin >> a;
      array.push_back(a);
    }
    int max = array[n - 1];
    if (array[0] + array[1] < max) {
      cout << 1 << " " << 2 << " " << n << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
