#include <bits/stdc++.h>
using namespace std;
int n;
int keep[101];
int tt[101];
int first[101];
int main() {
  while (cin >> n) {
    n *= 2;
    int sum = 0, n1 = 0, n2 = 0, s1 = 0, s2 = 0;
    memset(keep, 0, sizeof(keep));
    memset(first, 0, sizeof(first));
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      keep[a]++;
      tt[i] = a;
    }
    for (int i = 10; i < 100; i++) {
      if (keep[i] > 1) {
        s1++;
        s2++;
        if (n1 > n2)
          n1 += keep[i] / 2, n2 += (keep[i] - keep[i] / 2), first[i] = 2;
        else
          n2 += keep[i] / 2, n1 += (keep[i] - keep[i] / 2), first[i] = 1;
      } else if (keep[i] == 1)
        sum++;
    }
    int turn = 1;
    if (s1 > s2) {
      turn = 2;
      s1 += sum / 2;
      s2 += (sum - sum / 2);
    } else {
      turn = 2;
      s2 += sum / 2;
      s1 += (sum - sum / 2);
    }
    cout << s1 * s2 << endl;
    for (int i = 0; i < n; i++) {
      if (keep[tt[i]] > 1) {
        cout << first[tt[i]];
        first[tt[i]] = (first[tt[i]] == 2 ? 1 : 2);
      } else if (keep[tt[i]] == 1) {
        cout << turn;
        turn = (turn == 2 ? 1 : 2);
      }
      if (i < n - 1)
        cout << " ";
      else
        cout << endl;
    }
  }
}
