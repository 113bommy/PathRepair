#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long c = -2 * (a + b);
  if ((1 - 4 * c) < 0) {
    cout << 0 << endl << 0 << endl;
    return 0;
  }
  long long first = ((double)(-1 + sqrt(1 - 4 * c)) / 2);
  if (first < 0) {
    cout << 0 << endl << 0 << endl;
    return 0;
  }
  unordered_set<long long> arr, brr;
  long long i = first;
  while (a > 0 && i > 0) {
    if (a - i >= 0) {
      a -= i;
      arr.insert(i);
    }
    i--;
  }
  i = first;
  while (b > 0 && i > 0) {
    if (b - i >= 0 && arr.find(i) == arr.end()) {
      b -= i;
      brr.insert(i);
    }
    i--;
  }
  cout << arr.size() << endl;
  for (auto i : arr) cout << i << " ";
  cout << endl;
  cout << brr.size() << endl;
  for (auto i : brr) cout << i << " ";
  cout << endl;
}
