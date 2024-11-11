#include <bits/stdc++.h>
using namespace std;
using namespace std;
vector<int> a;
vector<int> last;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int max;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0)
      max = a[0];
    else if (max < a[i])
      max = a[i];
  }
  last.resize(max + 1, -1);
  for (int i = 0; i < n; i++) {
    last[a[i]] = i;
  }
  int min = n + 10;
  int min_i = -1;
  for (int i = 1; i < last.size(); i++) {
    if (last[i] < min && last[i] != -1) {
      min = last[i];
      min_i = i;
    }
  }
  cout << min_i;
  return 0;
}
