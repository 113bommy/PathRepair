#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100100];
long long int c[100100];
long long int a[100100];
int n, m;
int lowbit(int x) { return x & (-x); }
void update(int pos, int x) {
  while (pos <= m) {
    c[pos] += x;
    pos += lowbit(pos);
  }
}
long long int query(int pos) {
  long long int ans = 0;
  while (pos > 0) {
    ans += c[pos];
    pos -= lowbit(pos);
  }
  return ans;
}
int main() {
  cin >> n >> m;
  queue<int> tag;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
  }
  for (int i = 1; i <= m; i++) {
    if (vec[i].size() > 0) {
      tag.push(i);
    }
  }
  long long int ans = 0;
  for (int i = 1; i <= m; i++) {
    sort(vec[i].begin(), vec[i].end(), greater<int>());
  }
  int now = 1;
  while (tag.size()) {
    int len = tag.size();
    while (len--) {
      int x = tag.front();
      tag.pop();
      if (vec[x].size() < now) {
        update(x, -a[x]);
      } else {
        update(x, vec[x][now - 1]);
        a[x] += vec[x][now - 1];
        if (a[x] < 0)
          update(x, -a[x]);
        else
          tag.push(x);
      }
    }
    long long int temp = query(m);
    ans = max(ans, temp);
    now++;
  }
  cout << ans << endl;
}
