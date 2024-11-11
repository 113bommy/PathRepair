#include <bits/stdc++.h>
using namespace std;
int n, k;
const long long int INF = 1000000000000000000ll;
vector<pair<int, int> > pen;
vector<pair<int, int> > st;
long long int dp[1001][1001];
long long int rec(int N, int K) {
  if (N == 0) {
    if (K > 0) return INF;
    if (K == 0) return 0;
  }
  long long int& ret = dp[N][K];
}
int main() {
  cin >> n >> k;
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    sum += 2 * a;
    if (b == 1)
      st.push_back(pair<int, int>(2 * a, i));
    else
      pen.push_back(pair<int, int>(2 * a, i));
  }
  int K = k;
  sort(st.begin(), st.end());
  sort(pen.begin(), pen.end());
  vector<int> items[1001];
  if (st.size() >= k) {
    int i;
    for (i = st.size() - 1; k > 1; i--, k--) {
      sum -= st[i].first / 2;
      items[k - 1].push_back(st[i].second);
    }
    for (int j = 0; j <= i; j++) items[0].push_back(st[j].second);
    for (int j = pen.size() - 1; j >= 0; j--) items[0].push_back(pen[i].second);
    if (pen.size() > 0)
      sum -= (min(st[0].first, pen[0].first)) / 2;
    else
      sum -= st[0].first / 2;
  } else {
    for (int i = st.size() - 1; i >= 0; k--, i--) {
      sum -= st[i].first / 2;
      items[k - 1].push_back(st[i].second);
    }
    int p = pen.size() - 1;
    while (k > 0) {
      items[k - 1].push_back(pen[p].second);
      k--;
      p--;
    }
    while (p >= 0) {
      items[0].push_back(pen[p].second);
      p--;
    }
  }
  if (sum % 2 == 0)
    cout << sum / 2 << ".0" << endl;
  else
    cout << sum / 2 << ".5\n";
  for (int i = 0; i < K; i++) {
    cout << items[i].size() << " ";
    for (int j = items[i].size() - 1; j >= 0; j--)
      cout << items[i][j] + 1 << " ";
    cout << endl;
  }
  return 0;
}
