#include <bits/stdc++.h>
using namespace std;
int main() {
  int best = 1;
  int n;
  cin >> n;
  vector<int> processor(n);
  vector<int> ram(n);
  vector<int> hard(n);
  vector<int> cost(n);
  vector<int> notOutDated;
  for (int i = 0; i < n; i++) {
    cin >> processor[i];
    cin >> ram[i];
    cin >> hard[i];
    cin >> cost[i];
  }
  for (int i = 0; i < n; i++) {
    int j = 0;
    for (j = 0; j < n; j++) {
      if (i != j) {
        if (processor[j] > processor[i] && ram[j] > ram[i] &&
            hard[j] > hard[i]) {
          break;
        }
      }
    }
    if (j == n) notOutDated.push_back(i + 1);
  }
  best = notOutDated[0];
  for (int i = 1; i < notOutDated.size(); i++) {
    if (cost[notOutDated[i]] <= cost[best]) {
      best = notOutDated[i];
    }
  }
  cout << best << endl;
  return 0;
}
