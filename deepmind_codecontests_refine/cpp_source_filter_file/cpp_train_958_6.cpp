#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  long long index;
  cin >> s1 >> s2;
  vector<char> v;
  sort(s1.begin(), s1.end());
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] != '0') {
      index = i;
      break;
    }
  }
  swap(s1[index], s1[0]);
  if (s1 == s2)
    cout << "OK";
  else
    cout << "WRONG_ANSWER";
}
