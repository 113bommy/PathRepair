#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    vector<pair<int, int> > vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i].first;
      vec[i].second = i;
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i < n; i++) {
      if (vec[i].first == vec[i - 1].first) vec[i].first = vec[i - 1].first + 1;
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) res[vec[i].second] = vec[i].first;
    for (int i = 0; i < n - 1; i++) cout << res[i] << " ";
    cout << res[n - 1] << endl;
  }
}
