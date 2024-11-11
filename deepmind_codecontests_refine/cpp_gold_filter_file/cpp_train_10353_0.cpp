#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> res;
  int n, v, i, j, ni, sij;
  bool flag = false;
  cin >> n >> v;
  for (i = 0; i < n; i++) {
    flag = false;
    cin >> ni;
    for (j = 0; j < ni; j++) {
      cin >> sij;
      if (flag == false && sij < v) {
        flag = true;
        res.push_back(i + 1);
      }
    }
  }
  cout << res.size() << endl;
  for (auto i : res) cout << i << " ";
  return 0;
}
