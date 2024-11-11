#include <bits/stdc++.h>
using namespace std;
int A[1507], pre[1507], N, tmp, ans = 0, big = 0;
int getPre(int x) {
  if (x >= 0) return pre[x];
  return 0;
}
map<int, vector<pair<int, int> > > save;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    pre[i] = A[i] + getPre(i - 1);
    for (int j = 0; j <= i; j++) {
      tmp = pre[i] - getPre(j - 1);
      if ((save.count(tmp) && save[tmp].back().second < j) ||
          !save.count(tmp)) {
        save[tmp].push_back(make_pair(j, i));
        if (save[tmp].size() > big) {
          ans = tmp;
          big = save[tmp].size();
        }
      }
    }
  }
  cout << big << endl;
  for (int i = 0; i < big; i++)
    cout << save[ans][i].first + 1 << ' ' << save[ans][i].second + 1 << endl;
}
