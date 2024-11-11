#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> v[3010];
vector<long long> z;
long long answer = 9999999999999;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int p;
    long long c;
    scanf("%d%lld", &p, &c);
    v[p].push_back(c);
  }
  for (int i = 1; i <= m; i++) sort(v[i].begin(), v[i].end());
  for (int k = 1; k <= n; k++) {
    long long need = 0;
    int vote = v[1].size();
    z.clear();
    for (int j = 2; j <= m; j++)
      for (int l = 0; l < v[j].size(); l++) {
        if (l < (int)v[j].size() - k + 1) {
          vote++;
          need += v[j][l];
        } else {
          z.push_back(v[j][l]);
        }
      }
    sort(z.begin(), z.end());
    for (int i = 0; i < z.size(); i++) {
      if (vote == k) break;
      vote++;
      need += z[i];
    }
    if (vote < k) continue;
    answer = min(answer, need);
  }
  cout << answer << endl;
}
