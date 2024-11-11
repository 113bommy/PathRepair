#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> theval;
    map<int, int> ones;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      theval.push_back(a);
      if (b == 1) {
        ones[a]++;
      }
    }
    sort(theval.begin(), theval.end());
    map<int, vector<int>> rep;
    int sum = 1;
    int maximumsum = 1;
    for (int i = 1; i < n; i++) {
      if (theval[i] == theval[i - 1]) {
        sum++;
      } else {
        rep[sum].push_back(ones[theval[i - 1]]);
        sum = 1;
      }
      maximumsum = max(maximumsum, sum);
    }
    rep[sum].push_back(ones[theval[n - 1]]);
    int value1 = 0, value2 = 0;
    priority_queue<int> shahad;
    for (int i = maximumsum; i > 0; i--) {
      for (int j = 0; j < rep[i].size(); j++) {
        shahad.push(rep[i][j]);
      }
      if (shahad.size() > 0) {
        value1 += i, value2 += shahad.top();
        shahad.pop();
      }
    }
    std::cout << value1 << " " << value2 << endl;
  }
}
