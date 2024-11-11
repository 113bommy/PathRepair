#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long i, j, n, minn, temp, count = 0;
    vector<int> v;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> temp;
      v.push_back(temp);
    }
    minn = v[n - 1];
    for (i = n - 2; i >= 0; i--) {
      if (minn >= v[i]) {
        minn = v[i];
      } else {
        count++;
      }
    }
    cout << count << endl;
  }
}
