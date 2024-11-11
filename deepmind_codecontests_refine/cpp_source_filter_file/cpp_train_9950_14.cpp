#include <bits/stdc++.h>
using namespace std;
string a, b;
long long int pre[2000000 + 5], suff[2000000 + 5];
stack<char> buffer;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int i, j, cnt = 0, ans = 0, ind = 0;
  cin >> a >> b;
  j = 0;
  for (i = 0; i < (long long int)a.size(); i++) {
    if (a[i] == b[j] && j < (long long int)b.size()) {
      cnt++;
      j++;
    }
    pre[i] = cnt;
  }
  j = b.size() - 1;
  cnt = 0;
  for (i = (long long int)a.size() - 1; i >= 0; i--) {
    if (a[i] == b[j] && j >= 0) {
      cnt++;
      j--;
    }
    suff[i] = cnt;
  }
  suff[a.size()] = 0;
  ans = suff[0];
  ind = -1;
  for (i = 0; i < (long long int)a.size(); i++) {
    if (pre[i] + suff[i + 1] > ans) {
      ans = pre[i] + suff[i + 1];
      ind = i;
    }
  }
  j = 0;
  for (i = 0; i <= ind; i++) {
    if (a[i] == b[j] && j < (long long int)b.size()) {
      cout << b[j];
      j++;
    }
  }
  cnt = j;
  j = b.size() - 1;
  for (i = (long long int)a.size() - 1; i > ind; i--) {
    if (a[i] == b[j] && j >= 0 && cnt <= (long long int)b.size()) {
      buffer.push(b[j]);
      cnt++;
      j--;
    }
  }
  while (!(buffer.empty())) {
    cout << buffer.top();
    buffer.pop();
  }
  if (suff[0] == 0 && pre[a.size() - 1] == 0) cout << '-';
  cout << '\n';
  return 0;
}
