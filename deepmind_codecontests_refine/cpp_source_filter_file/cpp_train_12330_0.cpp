#include <bits/stdc++.h>
using namespace std;
int mark[100010];
int su[100010];
int Q[100010];
int cnt;
int main() {
  int a, b, c;
  char ch[2];
  cin >> a >> b;
  memset(mark, 0, sizeof(mark));
  memset(su, 0, sizeof(su));
  for (int i = 0; i < b; i++) {
    cin >> ch >> c;
    if (ch[0] == '+')
      Q[i] = c;
    else
      Q[i] = -c;
  }
  cnt = 0;
  for (int i = 0; i < b; i++) {
    if (Q[i] < 0) {
      su[-Q[i]]--;
      if (su[-Q[i]] < 0) {
        cnt++;
      }
    } else {
      su[Q[i]]++;
    }
  }
  for (int i = 0; i < b; i++) {
    if (Q[i] > 0) {
      if (i > 0) {
        if (Q[i - 1] != -Q[i]) mark[Q[i]] = 1;
      }
      if (cnt > 0) mark[Q[i]] = 1;
      cnt++;
    } else {
      cnt--;
      if (cnt > 0) mark[-Q[i]] = 1;
      if (i < b - 1) {
        if (Q[i + 1] != -Q[i]) mark[-Q[i]] = 1;
      }
    }
  }
  cnt = 0;
  for (int i = 1; i <= a; i++) {
    if (mark[i] == 0) cnt++;
  }
  cout << cnt << endl;
  for (int i = 1; i < a; i++) {
    if (mark[i] == 0) cout << i << ' ';
  }
  if (mark[a] == 0) cout << a;
  cout << endl;
  return 0;
}
