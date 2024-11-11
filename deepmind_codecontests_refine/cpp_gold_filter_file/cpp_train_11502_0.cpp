#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int amount = pow(2, n - 1), index = 1;
  vector<int> answer;
  while (index <= n) {
    if (m <= amount / 2)
      answer.push_back(index);
    else
      m -= amount / 2;
    amount = max(1, amount / 2);
    index += 1;
  }
  for (int i = 0; i < answer.size(); ++i) cout << answer[i] << " ";
  for (int i = n; i > 0; --i) {
    bool found = false;
    for (int j = 0; j < answer.size(); ++j)
      if (answer[j] == i) found = true;
    if (!found) cout << i << " ";
  }
  cout << endl;
}
