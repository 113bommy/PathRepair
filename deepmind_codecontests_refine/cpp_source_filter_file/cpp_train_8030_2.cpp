#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  int n;
  cin >> n;
  long long min;
  set<long long> ans;
  vector<long long> trueAns(n);
  vector<long long> qArr(n - 1);
  vector<long long> table(n, 0);
  for (int i = 0; i < qArr.size(); i++) {
    cin >> qArr[i];
  }
  for (int i = 1; i < table.size(); i++) {
    table[i] = qArr[i - 1] + table[i - 1];
  }
  min = table[0];
  for (int i = 1; i < table.size(); i++) {
    if (table[i] < min) min = table[i];
  }
  x = 1 - min;
  for (int i = 0; i < table.size(); i++) {
    ans.insert(x + table[i]);
    trueAns[i] = x + table[i];
  }
  if (ans.size() != n) {
    cout << -1;
    return 0;
  }
  for (auto i = ans.begin(), temp = ans.begin(); i != ans.end(); i++) {
    temp++;
    if (temp == ans.end()) break;
    if (*temp - *i != 1) {
      cout << -1;
      return 0;
    }
  }
  for (auto i : trueAns) {
    cout << i;
  }
  return 0;
}
