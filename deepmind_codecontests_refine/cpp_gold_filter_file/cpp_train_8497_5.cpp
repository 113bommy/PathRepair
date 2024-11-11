#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ar(n + 1);
  int sum = 0;
  vector<int> res1;
  for (int i = 0; i < n + 1; i++) {
    cin >> ar[i];
    for (int j = 0; j < ar[i]; j++) {
      res1.push_back(sum);
    }
    sum += ar[i];
  }
  sum = 0;
  for (int i = 0; i < n; i++) {
    sum += ar[i];
    if (ar[i] > 1 && ar[i + 1] > 1) {
      cout << "ambiguous\n";
      for (int x : res1) {
        cout << x << " ";
      }
      cout << "\n";
      for (int j = 0; j < res1.size(); j++) {
        if (j == sum + 1) {
          res1[j]--;
        }
        cout << res1[j] << " ";
      }
      return 0;
    }
  }
  cout << "perfect\n";
  return 0;
}
