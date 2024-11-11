#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long lock = 0;
  long long ss[100000];
  long long j = 0;
  deque<long long> q1, q2;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '(') q1.push_back(i + 1);
  for (int i = s.length() - 1; i >= 0; i--) {
    long long a = q1.front();
    if (a > i) break;
    if (s[i] == ')') {
      if (!q1.empty()) {
        q1.pop_front();
        ss[j++] = a;
        ss[j++] = i + 1;
      } else
        q2.push_back(i + 1);
    }
  }
  if (j == 0)
    cout << "0" << endl;
  else {
    sort(ss, ss + j);
    cout << "1" << endl << j << endl;
    for (int i = 0; i < j; i++) cout << ss[i] << " ";
    cout << endl;
  }
}
