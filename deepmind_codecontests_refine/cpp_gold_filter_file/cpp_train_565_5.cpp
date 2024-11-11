#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> n >> s;
  int cnt = 0, sum = 0, ans1 = 100005, ans2 = 100005;
  for (int i = 0; i < n; i++)
    if (s[i] == 'H') cnt++;
  for (int i = 0; i < n; i++)
    if (s[i] == 'T') sum++;
  for (int i = 0; i < n; i++) {
    int temp1 = 0, temp2;
    for (int j = i; j < i + cnt; j++) {
      if (s[j % n] != 'H') temp1++;
      if (s[j % n] != 'T') temp2++;
    }
    ans1 = min(ans1, temp1);
    ans2 = min(ans2, temp2);
  }
  cout << min(ans1, ans2) << endl;
}
