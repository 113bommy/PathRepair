#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;
int n, m, K;
int main() {
  cin >> n >> m >> K;
  vector<pair<int, int> > vec;
  for (int c = 0; c < n; c++) {
    vector<int> arr(m);
    for (int i = 0; i < m; i++) cin >> arr[i];
    if (K == 0) {
      for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
          if (arr[j] < arr[i]) {
            swap(arr[i], arr[j]);
            vec.push_back(make_pair(i + 1, j + 1));
          }
    } else {
      for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
          if (arr[j] > arr[i]) {
            swap(arr[i], arr[j]);
            vec.push_back(make_pair(j + 1, i + 1));
          }
        }
      }
    }
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  cout << vec.size() << endl;
  for (int i = 0; i < vec.size(); i++)
    cout << vec[i].first << " " << vec[i].second << endl;
  return 0;
}
