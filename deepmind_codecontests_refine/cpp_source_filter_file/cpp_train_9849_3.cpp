#include <bits/stdc++.h>
using namespace std;
const long long int infinity = 9e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  if ((n - k - 1) == 0) {
    cout << 2 << "\n";
    for (int i = 1; i < n; i++) {
      cout << 1 << " " << i + 1 << "\n";
    }
  } else if ((n - k - 1) == 1) {
    cout << 3 << "\n";
    cout << 1 << " " << 2 << "\n";
    cout << 1 << " " << 3 << "\n";
    for (int i = 3; i < n; i++) {
      cout << 2 << " " << i + 1 << "\n";
    }
  } else {
    long long int x = (n - k - 1) / k;
    long long int y = (n - k - 1) % k;
    vector<long long int> v;
    for (int i = 0; i < y; i++) {
      v.push_back(x + 1);
    }
    if (x) {
      for (int i = 0; i < k - y; i++) {
        v.push_back(x);
      }
    }
    cout << v[0] + v[1] + 2 << "\n";
    long long int value = 2;
    for (int i = 0; i < v.size(); i++) {
      cout << 1 << " " << value << "\n";
      for (int j = 0; j < v[i]; j++) {
        cout << value << " " << value + 1 << "\n";
        value++;
      }
      value++;
    }
    x = value - 2;
    for (int i = value; i < n + 1; i++) {
      cout << x << " " << value << "\n";
    }
  }
  return 0;
}
