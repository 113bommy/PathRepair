#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(90);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int n, s, h[1000], m[1000], ans = 0, hour, mn, ok1, ok2;
  bool flag = false;
  cin >> n >> s;
  ok2 = s * 2;
  ok2++;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    cin >> m[i];
  }
  for (int i = 0; i < n; i++) {
    if (h[0] * 60 + m[0] >= s + 1) {
      cout << "0"
           << " "
           << "0" << endl;
      return 0;
    }
    if (i == n - 1) {
      ok1 = abs((h[i] * 60 + m[i]) - (h[n - 1] * 60 + m[n - 1]));
      flag = true;
    } else if (i != n - 1) {
      ok1 = abs((h[i] * 60 + m[i]) - (h[i + 1] * 60 + m[i + 1]));
      flag = true;
    }
    if (ok1 > ok2 && flag == true) {
      ans = (h[i] * 60 + s + 1);
      hour = ans / 60;
      mn = ans % 60;
      cout << hour << " " << mn << endl;
      return 0;
    }
  }
  ans = h[n - 1] * 60 + m[n - 1] + s + 1;
  hour = ans / 60;
  mn = ans % 60;
  cout << hour << " " << mn << endl;
  return 0;
}
