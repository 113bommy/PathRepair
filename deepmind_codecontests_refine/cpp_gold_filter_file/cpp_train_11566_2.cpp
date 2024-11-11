#include <bits/stdc++.h>
using namespace std;
map<int, int> freq;
vector<int> vec;
int main() {
  int n, ans = 1, count = 1;
  vector<int> res;
  cin >> n;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    if (x == 1) freq[x]++;
    vec.push_back(x);
  }
  if (n == 1) {
    cout << freq[1] << endl;
    cout << 1 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (vec[i] == 1) {
      if (i == n - 1) {
        res.push_back(vec[i - 1]);
        res.push_back(1);
      } else
        res.push_back(vec[i - 1]);
    } else {
      if (i == n - 1) {
        res.push_back(vec[i]);
      } else
        continue;
    }
  }
  cout << freq[1] << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
