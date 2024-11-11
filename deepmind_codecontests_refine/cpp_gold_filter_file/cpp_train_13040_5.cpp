#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t) {
    int n;
    cin >> n;
    vector<vector<long>> array(n, vector<long>(2));
    long a = LONG_MAX, b = LONG_MAX;
    for (int i = 0; i < n; i++) {
      cin >> array[i][0];
      if (a > array[i][0]) a = array[i][0];
    }
    for (int i = 0; i < n; i++) {
      cin >> array[i][1];
      if (b > array[i][1]) b = array[i][1];
    }
    long long count = 0;
    for (int i = 0; i < n; i++) {
      if (array[i][0] > a && array[i][1] > b)
        count += max(array[i][0] - a, array[i][1] - b);
      else if (array[i][0] > a)
        count += array[i][0] - a;
      else if (array[i][1] > b)
        count += array[i][1] - b;
    }
    cout << count << "\n";
    t -= 1;
  }
  return 0;
}
