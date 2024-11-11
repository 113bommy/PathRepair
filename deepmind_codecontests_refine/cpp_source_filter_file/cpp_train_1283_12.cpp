#include <bits/stdc++.h>
using namespace std;
int n, m, i, num[100100], yes[100100], no[100010], ans_no = 0, ans_maybe = 0,
                                                   ans_is[10010];
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> num[i];
    if (num[i] > 0)
      yes[num[i]]++;
    else {
      no[-num[i]]++;
      ans_no++;
    }
  }
  for (i = 1; i <= n; i++) {
    if (yes[i] + ans_no - no[i] == m) {
      ans_is[i] = 1;
      ans_maybe++;
    }
  }
  for (i = 1; i <= n; i++) {
    if (num[i] > 0) {
      if (ans_maybe == 1 && ans_is[num[i]] == 1)
        cout << "Truth" << endl;
      else if (ans_is[num[i]] == 0)
        cout << "Lie" << endl;
      else
        cout << "Not defined" << endl;
    } else {
      if (ans_is[-num[i]] == 0)
        cout << "Truth" << endl;
      else if (ans_maybe == 1)
        cout << "Lie" << endl;
      else
        cout << "Not defined" << endl;
    }
  }
  return 0;
}
