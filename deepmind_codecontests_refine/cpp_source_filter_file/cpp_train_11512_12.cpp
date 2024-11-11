#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
const int dy[] = {-1, 0, 0, 1, 1, 1, -1, -1};
const int N = 0;
const int MOD = 0;
const int INF = 1e9 + 10;
const long long int LLINF = 1e18 + 10;
int n, k;
int v[200010];
vector<pair<int, int> > buraco;
vector<int> fin;
int ult = 0;
void build() {
  int j = 0;
  int idx = 0;
  while (j < n) {
    int val = v[j];
    int cnt = 0;
    if (val < 0) {
      while (j < n && v[j] < 0) {
        j++;
        cnt++;
      }
    } else {
      while (j < n && v[j] >= 0) {
        j++;
        cnt++;
      }
      buraco.push_back(make_pair(cnt, idx));
    }
    fin.push_back(val < 0 ? -1 : 1);
    idx++;
  }
  ult = -1;
  if (fin[fin.size() - 1] == 1) {
    ult = buraco[buraco.size() - 1].first;
    buraco.erase(buraco.begin() + buraco.size() - 1);
  }
  sort(buraco.begin(), buraco.end());
}
int main() {
  cin >> n >> k;
  int neg = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    neg += (v[i] < 0);
  }
  build();
  int disponivel = k - neg;
  if (disponivel < 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < buraco.size(); i++) {
    if (buraco[i].second == 0) continue;
    if (disponivel < buraco[i].first) break;
    disponivel -= buraco[i].first;
    fin[buraco[i].second] = -1;
  }
  int ans = fin[0] < 0;
  for (int i = 1; i < fin.size(); i++) {
    ans += fin[i] != fin[i - 1];
  }
  if (ult != -1 && disponivel >= ult) ans--;
  cout << ans << endl;
  return 0;
}
