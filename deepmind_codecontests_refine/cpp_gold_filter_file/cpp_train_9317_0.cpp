#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int main() {
  int n;
  cin >> n;
  ans.push_back(n);
  while (n != 1) {
    bool b = false;
    double sq = sqrt(n + 0.01);
    int i = 2;
    while (i <= sq) {
      if (n % i == 0) {
        b = true;
        n /= i;
        ans.push_back(n);
        break;
      }
      i++;
    }
    if (b == false) {
      ans.push_back(1);
      break;
    }
  }
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
