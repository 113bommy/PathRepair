#include <bits/stdc++.h>
using namespace std;
const char duom[] = "i.txt";
int a[200005];
vector<int> b;
int ans;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  char prev = '?';
  char c;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c != prev && i != 0) {
      prev = c;
      sort(b.begin(), b.end(), greater<int>());
      int limit = b.size();
      if (b.size() > k) limit = k;
      for (int j = 0; j < limit; j++) {
        ans += b[j];
      }
      b.clear();
    }
    prev = c;
    b.push_back(a[i]);
  }
  sort(b.begin(), b.end(), greater<int>());
  int limit = b.size();
  if (b.size() > k) limit = k;
  for (int j = 0; j < limit; j++) {
    ans += b[j];
  }
  cout << ans;
  return 0;
}
