#include <bits/stdc++.h>
using namespace std;
int n;
long long t;
long long a[200010];
int b[200010];
vector<long long> un;
void Insert(int x) {
  for (int i = x + 1; i > 0; i -= i & -i) b[i]++;
}
int Get(int x) {
  int res = 0;
  for (int i = x + 1; i < 200000; i += i & -i) res += b[i];
  return res;
}
int main() {
  cin >> n >> t;
  un.push_back(0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    un.push_back(a[i]);
  }
  sort(un.begin(), un.end());
  un.erase(unique(un.begin(), un.end()), un.end());
  long long res = 0;
  int ind = lower_bound(un.begin(), un.end(), 0LL) - un.begin();
  Insert(ind);
  for (int i = 1; i <= n; i++) {
    ind = upper_bound(un.begin(), un.end(), a[i] - t) - un.begin();
    res += Get(ind);
    ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
    Insert(ind);
  }
  cout << res << '\n';
  return 0;
}
