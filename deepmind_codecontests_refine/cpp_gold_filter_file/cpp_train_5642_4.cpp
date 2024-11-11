#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    map<int, int> num;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      num[a[i]] = 0;
    }
    list<int> var;
    int min1 = 0;
    for (int i = 0; i < d; i++) {
      var.push_back(a[i]);
      if (num[a[i]] == 0) {
        min1++;
      }
      num[a[i]]++;
    }
    int min2 = min1;
    int temp = min1;
    for (int i = d; i < n; i++) {
      int c;
      c = var.front();
      if (num[c] == 1) {
        temp--;
      }
      var.pop_front();
      num[c]--;
      if (num[a[i]] == 0) {
        temp++;
      }
      var.push_back(a[i]);
      num[a[i]]++;
      min2 = min(temp, min2);
    }
    cout << min2 << "\n";
  }
  return 0;
}
