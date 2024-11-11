#include <bits/stdc++.h>
using namespace std;
bool myComp(vector<int> const& A, vector<int> const& B) { return A[0] < B[0]; }
int main() {
  int N, max, reg;
  cin >> N >> max >> reg;
  vector<vector<vector<int>>> arr(101, vector<vector<int>>());
  for (int n = 0; n < N; n++) {
    int ind;
    vector<int> tmp(2, 0);
    cin >> ind >> tmp[0];
    tmp[1] = n;
    arr[ind].push_back(tmp);
  }
  for (int i = 0; i <= 100; i++) {
    sort(arr[i].begin(), arr[i].end(), myComp);
  }
  int dmg = 0;
  int res = 0;
  vector<vector<int>> sol;
  vector<vector<int>> collect;
  for (int i = 0; i < arr[100].size(); i++) {
    collect.push_back(arr[100][i]);
  }
  int state = 0;
  int num = max;
  while (dmg <= reg) {
    if (collect.empty()) {
      state = -1;
      break;
    }
    dmg += collect.back()[0];
    vector<int> tmp(2, res);
    tmp[0] = collect.back()[1];
    sol.push_back(tmp);
    res += 1;
    num = dmg > reg ? max - dmg + reg : max;
    collect.pop_back();
  }
  if (state >= 0) {
    int ind = 99;
    while (num > 0) {
      while (ind >= 0 && num * 100 <= ind * max) {
        for (int i = 0; i < arr[ind].size(); i++) {
          auto pr =
              lower_bound(collect.begin(), collect.end(), arr[ind][i], myComp);
          collect.insert(pr, arr[ind][i]);
        }
        ind--;
      }
      if (!collect.empty()) {
        dmg += collect.back()[0];
        vector<int> tmp(2, res);
        tmp[0] = collect.back()[1];
        sol.push_back(tmp);
        collect.pop_back();
      }
      res++;
      num -= dmg - reg;
    }
  }
  if (state < 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << res << " " << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++) {
      cout << sol[i][1] << " " << sol[i][0] + 1 << endl;
    }
  }
  return 0;
}
