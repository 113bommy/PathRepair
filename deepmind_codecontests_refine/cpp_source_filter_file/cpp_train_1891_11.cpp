#include <bits/stdc++.h>
using namespace std;
void solve() {
  int nums[] = {4, 8, 15, 16, 23, 42};
  map<int, pair<int, int>> pros;
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      pros[nums[i] * nums[j]] = {nums[i], nums[j]};
    }
  }
  vector<int> ans(6);
  cout << "? 1 1" << endl;
  int first;
  cin >> first;
  ans[0] = sqrt(first);
  cout << "? 2 2" << endl;
  int second;
  cin >> second;
  ans[1] = sqrt(second);
  cout << "? 3 4" << endl;
  int firstpro;
  cin >> firstpro;
  cout << "? 4 5" << endl;
  int secondpro;
  cin >> secondpro;
  pair<int, int> fp = pros[firstpro], sp = pros[secondpro];
  int cnts[100];
  memset(cnts, 0, sizeof cnts);
  cnts[fp.first]++;
  cnts[fp.second]++;
  cnts[sp.first]++;
  cnts[sp.second]++;
  if (cnts[fp.first] == 2) {
    ans[3] = fp.first;
    ans[2] = fp.second;
    if (cnts[sp.first] == 2) {
      ans[4] = sp.second;
    } else
      ans[4] = sp.first;
  } else {
    ans[3] = fp.second;
    ans[2] = fp.first;
    if (cnts[sp.first] == 2) {
      ans[4] = sp.second;
    } else
      ans[4] = sp.first;
  }
  bool marked[100];
  memset(marked, false, sizeof marked);
  for (int i = 0; i < 5; i++) marked[nums[i]] = true;
  for (int i = 0; i < 6; i++)
    if (!marked[nums[i]]) ans[5] = nums[i];
  cout << "! ";
  for (int i = 0; i < 6; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
