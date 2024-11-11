#include <bits/stdc++.h>
using namespace std;
int n, k;
string str;
queue<int> q;
int findOwnerPos() {
  int s = q.front();
  int e = q.back();
  int mid = s + (e - s) / 2;
  int m_p, m_n;
  if (((e - s + 1)) % 2 == 1) {
    if (str[mid] == '0') return max(e - mid, mid - s);
    m_p = mid - 1;
    m_n = mid + 1;
  } else {
    m_p = mid;
    m_n = mid + 1;
  }
  while (m_p >= s && m_n <= e) {
    if (str[m_p] == '0') return max(e - m_p, m_p - s);
    if (str[m_n] == '0') return max(e - m_n, m_n - s);
    m_p--;
    m_n++;
  }
}
int main() {
  cin >> n >> k >> str;
  int l = 0, i = 0;
  while (i < n) {
    if (str[i] == '0') {
      l++;
      q.push(i);
      if (l == k + 1) break;
    }
    i++;
  }
  int ans = INT_MAX;
  int pos = findOwnerPos();
  ans = min(ans, pos);
  i++;
  while (i < n) {
    if (str[i] == '0') {
      q.pop();
      q.push(i);
      pos = findOwnerPos();
      ans = min(ans, pos);
    }
    i++;
  }
  cout << ans << endl;
  return 0;
}
