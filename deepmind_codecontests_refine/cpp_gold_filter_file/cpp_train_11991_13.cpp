#include <bits/stdc++.h>
using namespace std;
int minPrefix[200000 + 3], maxSuffix[200000 + 3], answer;
string s, t;
int main() {
  cin >> s >> t;
  int ptrS;
  ptrS = 0;
  for (int i = 0; i < t.length(); i++) {
    while (s[ptrS] != t[i]) ptrS += 1;
    minPrefix[i + 1] = ptrS + 1;
    ptrS += 1;
  }
  ptrS = s.length() - 1;
  for (int i = t.length() - 1; i >= 0; i--) {
    while (s[ptrS] != t[i]) ptrS -= 1;
    maxSuffix[i + 1] = ptrS + 1;
    ptrS -= 1;
  }
  if (false) {
    for (int i = 1; i <= t.length(); i++) {
      cout << minPrefix[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= t.length(); i++) {
      cout << maxSuffix[i] << " ";
    }
    cout << endl;
  }
  answer = max((int)s.length() - minPrefix[t.length()], maxSuffix[1] - 1);
  for (int i = 1; i < t.length(); i++) {
    answer = max(answer, maxSuffix[i + 1] - minPrefix[i] - 1);
  }
  cout << answer << endl;
}
