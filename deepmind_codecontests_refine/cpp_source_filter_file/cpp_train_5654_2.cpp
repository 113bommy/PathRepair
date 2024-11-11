#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, oh, wow;
  cin >> n >> oh >> wow;
  vector<int> res;
  res.push_back(1);
  int sum = 1;
  for (int i = 0; i < wow; i++) {
    res.push_back(sum + 1);
    sum += sum + 1;
  }
  if (!wow) res.push_back(1);
  for (int i = 0; i < oh; i++) {
    res.push_back(res.back() + 1);
  }
  while ((int)res.size() < n) res.push_back(1);
  if ((int)res.size() > n) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
    if (res[i] > 50000) {
      cout << "-1\n";
      return 0;
    }
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << res[i];
  }
  cout << "\n";
}
