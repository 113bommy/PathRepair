#include <bits/stdc++.h>
using namespace std;
const long long hell = 1000000007LL;
const long long INF = hell * hell;
const int MAXN = 1e5;
int main() {
  if (!0) {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
  }
  int N, i, j;
  cin >> N;
  vector<int> a(N), b(N), pos(N + 1);
  vector<pair<int, int> > steps;
  for (i = 0; i < N; i++) cin >> a[i];
  for (i = 0; i < N; i++) {
    cin >> b[i];
    pos[b[i]] = i;
  }
  int res = 0;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      if (a[j] == b[N - 1 - i]) break;
    int k = j + 1;
    int x = a[j];
    while (j != N - 1 - i) {
      if (pos[a[k]] <= j) {
        swap(a[k], a[j]);
        steps.push_back(make_pair(j, k));
        res += k - j;
        j = k;
      }
      ++k;
    }
  }
  cout << res << "\n" << steps.size() << "\n";
  for (auto it = (steps).begin(); it != (steps).end(); it++)
    cout << it->first + 1 << " " << it->second + 1 << "\n";
}
