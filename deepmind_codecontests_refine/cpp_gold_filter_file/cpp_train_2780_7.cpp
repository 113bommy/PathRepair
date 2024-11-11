#include <bits/stdc++.h>
using namespace std;
int tot, toz, nm[11];
long long ans, tom = 1, mul[20];
vector<pair<int, int> > num;
void dfs(int x) {
  for (int i = 1; i <= num[x].second; i++) {
    tot++;
    tom *= i;
    if (!num[x].first) toz = i;
    if (x == num.size() - 1) {
      ans += mul[tot] * (tot - toz) / tom / tot;
      continue;
    }
    dfs(x + 1);
    tot -= num[x + 1].second;
    tom /= mul[num[x + 1].second];
  }
}
int main() {
  string n;
  cin >> n;
  for (int i = 0; i < n.size(); i++) nm[n[i] - '0']++;
  for (int i = 0; i < 10; i++)
    if (nm[i]) num.push_back(make_pair(i, nm[i]));
  mul[1] = 1;
  for (int i = 2; i < 20; i++) mul[i] = mul[i - 1] * i;
  dfs(0);
  cout << ans << endl;
}
