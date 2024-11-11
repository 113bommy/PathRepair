#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p = 1;
    int count;
    vector<int> res;
    while (n) {
      int x = n % 10;
      if (x != 0) {
        res.push_back(x * p);
        count++;
      }
      p *= 10;
      n /= 10;
    }
    cout << count << endl;
    for (int i = 0; i < res.size(); i++) {
      cout << res[i] << " ";
    }
    cout << endl;
  }
}
