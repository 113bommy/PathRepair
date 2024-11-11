#include <bits/stdc++.h>
using namespace std;
int score[100000] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
map<string, vector<int> > m1, m2;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      string s;
      cin >> s;
      if (!m1.count(s)) {
        m1[s] = vector<int>(110, 0);
        m2[s] = vector<int>(110, 0);
      }
      vector<int>& v1 = m1[s];
      vector<int>& v2 = m2[s];
      v1[0] += score[i];
      v2[1] += score[i];
      if (j == 0) {
        v1[1]++;
        v2[0]++;
      } else {
        v1[j + 1]++;
        v2[j + 1]++;
      }
    }
  }
  string r1 = "", r2 = "";
  vector<int> vr1(110, -1);
  vector<int> vr2(110, -1);
  for (map<string, vector<int> >::iterator it = m1.begin(); it != m1.end();
       it++) {
    if (it->second > vr1) {
      vr1 = it->second;
      r1 = it->first;
    }
  }
  for (map<string, vector<int> >::iterator it = m2.begin(); it != m2.end();
       it++) {
    if (it->second > vr2) {
      vr2 = it->second;
      r2 = it->first;
    }
  }
  cout << r1 << endl;
  cout << r2 << endl;
  return 0;
}
