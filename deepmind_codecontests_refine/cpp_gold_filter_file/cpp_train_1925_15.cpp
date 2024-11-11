#include <bits/stdc++.h>
using namespace std;
int _search(int i, int n, vector<int> &mio) {
  int ans = i;
  for (int j = i + 1; j < n; ++j)
    if (mio[j] < mio[ans]) ans = j;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  map<int, int> cod;
  int n;
  cin >> n;
  int _id = 0;
  vector<int> original(n);
  queue<int> target[n];
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (cod.count(t) == 0) cod[t] = _id++;
    target[cod[t]].push(i);
  }
  vector<int> mio(n);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    mio[i] = target[cod[t]].front();
    target[cod[t]].pop();
  }
  vector<pair<int, int> > answer;
  for (int i = 0; i < n; ++i) {
    int j = _search(i, n, mio);
    for (int k = j; k > i; k--) {
      swap(mio[k], mio[k - 1]);
      answer.push_back(make_pair(k + 1, k));
    }
  }
  cout << answer.size() << endl;
  for (int i = 0; i < answer.size(); ++i) {
    cout << min(answer[i].first, answer[i].second) << " "
         << max(answer[i].first, answer[i].second) << endl;
  }
  return 0;
}
