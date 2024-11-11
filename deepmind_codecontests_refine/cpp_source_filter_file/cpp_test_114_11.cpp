#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, temp;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      v.push_back(temp);
    }
    sort(v.begin(), v.end());
    n /= 2;
    int j = 1;
    while (n--) {
      cout << v[0] << " " << v[j] << "\n";
      j += 1;
    }
  }
}
