#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> list;
    int max_value = -1;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      list.push_back(temp);
    }
    sort((list).begin(), (list).end());
    int change = 0;
    for (int i = 0; i < list.size(); i++) {
      list[i] = list[i] - change;
      max_value = max(list[i], max_value);
      change += list[i];
    }
    cout << max_value << '\n';
    ;
  }
  return 0;
}
