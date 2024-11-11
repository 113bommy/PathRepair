#include <bits/stdc++.h>
using namespace std;
int a, m;
vector<int> ans;
int main() {
  cin >> a >> m;
  ans.push_back(m);
  while (m % 2 == 0) {
    m /= 2;
    ans.push_back(m);
  }
  for (int i = 0; i < ans.size(); ++i)
    if (a % ans[i] == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  cout << "No" << endl;
  return 0;
}
