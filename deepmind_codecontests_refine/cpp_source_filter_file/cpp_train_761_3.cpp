#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int> > A;
map<pair<int, int>, int> M;
int main() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
    M[make_pair(A[i].first, A[i].second)]++;
  }
  int ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) {
      if ((A[j].first - A[i].first) % 2 == 1 ||
          (A[j].second - A[i].second) % 2 == 1)
        continue;
      int x = A[i].first + (A[j].first - A[i].first) / 2;
      int y = A[i].second + (A[j].second - A[i].second) / 2;
      if (M.find(make_pair(x, y)) != M.end()) ans += M[make_pair(x, y)];
    }
  cout << ans << endl;
  return 0;
}
