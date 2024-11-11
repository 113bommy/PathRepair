#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> s;
  n = stoi(s);
  while (n-- > 0) {
    cin >> s;
    int t = stoi(s);
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    vector<int> enemy;
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] == '1') {
        enemy.push_back(i);
      }
    }
    int cnt = 0;
    for (int i = 0; i < s2.size(); i++) {
      if (s2[i] == '1' && s1[i] == '0') {
        cnt++;
        continue;
      }
      if (s2[i] == '1' && s1[i] == '1') {
        if (i != 0 && s1[i - 1] == '1') {
          s1[i - 1] = '2';
          cnt++;
          continue;
        }
        if (i != t - 1 && s1[i + 1] == '1') {
          s1[i + 1] = '2';
          cnt++;
          continue;
        }
      }
    }
    cout << cnt << endl;
  }
}
