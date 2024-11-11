#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    int d = i + 1 - val;
    if (d >= 0) {
      a.push_back({d, val});
    }
  }
  sort(a.begin(), a.end());
  vector<int> b(a.size());
  for (int i = 0; i < a.size(); i++) {
    b[i] = a[i].second;
  }
  vector<int> tails;
  for (int i = 0; i < a.size(); i++) {
    int k = tails.size();
    int index =
        upper_bound(tails.begin(), tails.end(), b[i] - 1) - tails.begin() - 1;
    if (k == 0) {
      tails.push_back(b[i]);
    } else if (index == -1) {
      tails[0] = b[i];
    } else if (index == k - 1) {
      if (tails[k - 1] != b[i]) {
        tails.push_back(b[i]);
      }
    } else {
      tails[index + 1] = b[i];
    }
  }
  cout << tails.size() << endl;
}
