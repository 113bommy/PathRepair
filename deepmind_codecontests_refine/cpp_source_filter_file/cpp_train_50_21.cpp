#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(m + 1, 0);
  for (int i = 0; i < (n); ++i) {
    int tot, num;
    cin >> tot;
    for (int j = 0; j < (tot); ++j) cin >> num, vec[num] = 1;
  }
  int sum = 0;
  for (int i = 0; i < (m); ++i) sum += vec[i];
  if (sum < m)
    cout << "No\n";
  else
    cout << "Yes\n";
}
