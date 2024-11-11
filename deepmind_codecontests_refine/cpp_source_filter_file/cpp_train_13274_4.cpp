#include <bits/stdc++.h>
using namespace std;
vector<string> rep(int i, int k, vector<string> a) {
  vector<string> res;
  res = a;
  for (int i = 0; i < a.size(); i++) res[i] += a[i];
  for (int i = 0; i < a[0].length(); i++) res.push_back(a[i]);
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a[0].length(); j++)
      if (a[i][j] == '+')
        a[i][j] = '*';
      else
        a[i][j] = '+';
  for (int i = 0; i < a.size(); i++) res[a.size() + i] += a[i];
  if (i < k) res = rep(i + 1, k, res);
  return res;
}
int main() {
  int k;
  cin >> k;
  vector<string> result(1, "+");
  if (k > 1) result = rep(2, k, result);
  for (int i = 0; i < result.size(); i++) cout << result[i] << endl;
}
