#include <bits/stdc++.h>
using namespace std;
struct node {
  int to, min = INT_MAX;
  long long sum = 0;
};
vector<int> t(int(1e5 + 9)), w(int(1e5 + 9));
vector<vector<node>> bs(40, vector<node>(int(1e5 + 9)));
void solve(int x, int k) {
  int min_ = INT_MAX;
  long long sum = 0;
  for (int i = 0; i < 35; i++) {
    if (!(k & (1LL << i))) continue;
    sum += bs[i][x].sum;
    min_ = min(min_, bs[i][x].min);
    x = bs[i][x].to;
  }
  cout << sum << " " << min_ << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) {
    bs[0][i].to = t[i];
    bs[0][i].sum = w[i];
    bs[0][i].min = w[i];
  }
  for (int i = 1; i < 40; i++)
    for (int j = 0; j < n; j++) {
      bs[i][j].to = bs[i - 1][bs[i - 1][j].to].to;
      bs[i][j].sum = bs[i - 1][j].sum + bs[i - 1][bs[i - 1][j].to].sum;
      bs[i][j].min = min(bs[i - 1][j].min, bs[i - 1][bs[i - 1][j].to].min);
    }
  for (int i = 0; i < n; i++) solve(i, k);
  return 0;
}
