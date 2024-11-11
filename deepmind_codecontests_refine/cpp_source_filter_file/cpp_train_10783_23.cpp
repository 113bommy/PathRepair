#include <bits/stdc++.h>
using namespace std;
void display(vector<int> v1) {
  for (long long int i = 0; i < v1.size(); i++) {
    cout << v1[i] << " ";
  }
  cout << endl;
}
long long int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
long long int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
long long int m, r;
bool cool(long long int i) { return m - (i * (i + 1)) / 2 <= (r + i + 1); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> m >> r;
  if (r <= m) {
    cout << r << endl;
    return 0;
  }
  long long int high = (long long int)2e9;
  long long int low = 0;
  long long int ans = high;
  while (high >= low) {
    float mid = (long long int)((high + low) / 2);
    if (cool(mid)) {
      ans = min(ans, (long long int)mid);
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (cool(ans - 1)) {
    ans -= 1;
  }
  if (cool(ans) == false && cool(ans + 1) == true) {
    ans += 1;
  }
  cout << r + ans + 1 << endl;
  return 0;
}
