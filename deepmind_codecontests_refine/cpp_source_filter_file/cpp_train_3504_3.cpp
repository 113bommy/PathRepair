#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  vector<long long> input(n);
  for (int i = 0; i < n; i++) cin >> input[i];
  queue<long long> q[70];
  for (int i = 0; i < n; i++) {
    long long cur = -1;
    for (int j = 60; j >= 0; j--) {
      if (input[i] & (1LL << j)) {
        cur = j;
        break;
      }
    }
    q[cur].push(i);
  }
  long long num = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int index = -1;
    for (int j = 0; j <= 60; j++) {
      if (((num & (1LL << j)) == 0) && q[j].size()) {
        index = q[j].front();
        q[j].pop();
        break;
      }
    }
    if (index == -1) {
      cout << "No" << endl;
      return 0;
    }
    num = num ^ input[index];
    ans.push_back(input[index]);
  }
  cout << "Yes" << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
