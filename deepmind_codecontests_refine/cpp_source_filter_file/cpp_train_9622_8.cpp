#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  while (cin >> n) {
    int goal = 1, sum = 0, temp;
    vector<int> res;
    for (int i = 0; i < (n); i++) {
      cin >> temp;
      sum += temp;
      if (temp == goal) {
        res.push_back(temp);
        goal++;
      }
    }
    cout << res.size() << endl;
    for (int i = 0; i < ((int)res.size()); i++) cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
