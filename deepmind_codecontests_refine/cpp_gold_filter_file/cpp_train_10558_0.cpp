#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  string str;
  cin >> str;
  std::deque<char> dq;
  int len = str.size();
  int l = 0, r = 0;
  int mid = 0;
  for (int i = (0); i < (len); ++i) {
    if (mid == 0 && str[i] != '|') {
      ++l;
    } else if (str[i] == '|') {
      ++mid;
      dq.push_back(str[i]);
      continue;
    } else
      r++;
    dq.push_back(str[i]);
  }
  string next;
  cin >> next;
  len = next.size();
  int diff = max(l - r, r - l);
  if (diff > len) {
    cout << "Impossible\n";
    return 0;
  }
  int k = 0;
  while (diff) {
    if (l < r) {
      dq.push_front(next[k++]);
    } else {
      dq.push_back(next[k++]);
    }
    --diff;
  }
  if ((len - k) & 1) {
    cout << "Impossible\n";
    return 0;
  }
  int flag = 0;
  for (int i = (k); i <= (len - 1); ++i) {
    if (flag == 0) {
      dq.push_front(next[i]);
    } else {
      dq.push_back(next[i]);
    }
    flag ^= 1;
  }
  len = dq.size();
  for (int i = (0); i <= (len - 1); ++i) {
    cout << dq[i];
  }
  cout << endl;
  return 0;
}
