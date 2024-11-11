#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  vector<int> g;
  for (int i = 0; i < n - 1; i++) {
    int temp;
    cin >> temp;
    g.push_back(temp);
  }
  int flag = 0;
  for (int i = 1; i <= t;) {
    if (i == t) {
      flag = 1;
      break;
    }
    i = i + g[i - 1];
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
