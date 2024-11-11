#include <bits/stdc++.h>
using namespace std;
using namespace std;
void chekarre(int* arr, int n) {
  cout << "[";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "]" << endl;
}
int n, m;
string s;
vector<int> vec[27];
int solve() {
  string tmp;
  int pos = -1;
  for (int i = 0; i < s.length(); i++) {
    vec[s[i] - 'a'].push_back(i);
  }
  for (int i = 26; i >= 0; i--) {
    for (int j = 0; j < vec[i].size(); j++) {
      if (pos < vec[i][j]) {
        tmp += (char)(i + 'a');
        pos = vec[i][j];
      }
    }
  }
  cout << tmp;
  return 1;
}
bool input() {
  cin >> s;
  return true;
}
int main() {
  int T = 1;
  for (int testnum = 1; testnum <= T; testnum++) {
    if (!input()) break;
    solve();
  }
  return 0;
}
