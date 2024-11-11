#include <bits/stdc++.h>
using namespace std;
long long n, m, k = 0;
string ss[100], s[200001];
int main() {
  cin >> n >> m;
  for (char i = 'A'; i <= 'B'; i++)
    for (char j = 'a'; j <= 'z'; j++) {
      string st;
      st += i;
      st += j;
      ss[k] = st;
      st = "";
      k++;
    }
  for (int i = 0; i < n - m + 1; i++) {
    cin >> s[i];
  }
  k = 0;
  for (int i = m - 1; i < n; i++) {
    if (s[k] == "NO") ss[i] = ss[i - (m - 1)];
    k++;
  }
  for (int i = 0; i < n; i++) cout << ss[i] << " ";
  return 0;
}
