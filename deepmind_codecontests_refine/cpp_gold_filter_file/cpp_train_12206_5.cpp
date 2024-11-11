#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  vector<int> ans;
  long long int sum = 0;
  long long int counter = 0;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    sum += p;
    v.push_back(p);
  }
  for (int i = 0; i < v.size(); i++) {
    long double q = sum;
    q = q - v[i];
    q = q / (n - 1);
    if (v[i] == q) {
      counter++;
      ans.push_back(i);
    }
  }
  cout << counter << endl;
  bool b = false;
  for (int i = 0; i < ans.size(); i++) {
    if (b) cout << " ";
    cout << ans[i] + 1;
    b = true;
  }
  return 0;
}
