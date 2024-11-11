#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> s(3);
  vector<int> n(3, 0);
  int now_s = 0;
  cin >> s[0] >> s[1] >> s[2];
  while (n[now_s] != s[now_s].size()) {
    n[now_s]++;
    now_s = s[now_s][n[now_s - 1]] - 'a';
  }
  cout << (char)(now_s + 'A') << endl;
}
