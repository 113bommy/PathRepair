#include <bits/stdc++.h>
using namespace std;
const int AKA = 5e5 + 5;
int frq[AKA];
bool mark[2 * 10000];
pair<int, int> a[2 * 10000];
int n, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i].first = x;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  int profit = 0;
  for (int i = n - k + 1; i <= n; i++) {
    profit += a[i].first;
    mark[a[i].second] = true;
  }
  cout << profit << endl;
  int lst = 0;
  int lft = n;
  for (int i = 1; i <= n; i++) {
    if (mark[i]) {
      if (k == 1) {
        cout << lft << " ";
        return 0;
      } else {
        cout << i - lst << " ";
        lft -= i - lst;
        k--;
      }
      lst = i;
    }
  }
}
