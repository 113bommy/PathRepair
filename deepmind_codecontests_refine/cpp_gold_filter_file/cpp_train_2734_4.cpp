#include <bits/stdc++.h>
using namespace std;
string f(vector<int> a) {
  int n = a.size();
  if (n <= 1) return "YES";
  for (int i = 1; i < n; i++) {
    if ((a[i] - a[i - 1]) > 1) return "NO";
  }
  return "YES";
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    cout << f(a) << endl;
  }
  return 0;
}
