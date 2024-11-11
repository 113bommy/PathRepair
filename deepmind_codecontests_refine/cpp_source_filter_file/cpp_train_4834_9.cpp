#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, min, tmp, hits;
  cin >> n;
  cin >> m;
  cin >> k;
  vector<int> jump(m);
  vector<int> com(k);
  vector<int> result(m);
  for (int i = 0; i < m; i++) cin >> jump[i];
  for (int i = 0; i < k; i++) cin >> com[i];
  min = k;
  for (int i = 0; i < m; i++) {
    hits = 0;
    for (int j = 0; j < k; j++) {
      if (com[j] % jump[i] == 0) hits++;
    }
    if (hits == min) {
      result.push_back(i);
    }
    if (hits < min) {
      min = hits;
      result.clear();
      result.push_back(i);
    }
  }
  cout << result.size() << endl;
  for (int i = 0; i < result.size(); i++) {
    result[i]++;
    cout << result[i] << " ";
  }
}
