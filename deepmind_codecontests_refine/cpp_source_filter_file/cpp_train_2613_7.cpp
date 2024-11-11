#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int n, ans, tmp[400000], x, dem;
priority_queue<int, vector<int> > buy;
priority_queue<int, vector<int>, greater<int> > sell;
void xuly(int x) {
  for (int i = (1); i <= (dem); i++) {
    if (tmp[i] == x) continue;
    if (tmp[i] < x)
      sell.push(tmp[i]);
    else
      buy.push(tmp[i]);
  }
  return;
}
int main() {
  cin >> n;
  ans = 1;
  int l = 0, r = INF;
  for (int i = (1); i <= (n); i++) {
    string c;
    cin >> c;
    if (c == "ADD") {
      cin >> x;
      tmp[++dem] = x;
    } else {
      cin >> x;
      if (x < l || x > r) return cout << 0, 0;
      bool flag = true;
      if (x == l) sell.pop(), flag = false;
      if (x == r) buy.pop(), flag = false;
      xuly(x);
      if (flag) ans = ans * 2 % INF;
      if (!sell.empty())
        l = sell.top();
      else
        l = 0;
      if (!buy.empty())
        r = buy.top();
      else
        r = INF;
      dem = 0;
    }
  }
  if (dem == 0)
    cout << ans;
  else {
    int sum = 0;
    for (int i = (1); i <= (dem); i++) {
      if (tmp[i] < l)
        sell.push(tmp[i]);
      else if (tmp[i] > r)
        buy.push(tmp[i]);
      else
        sum++;
    }
    ans = 1ll * ans * (sum + 1) % INF;
    cout << ans;
  }
  return 0;
}
