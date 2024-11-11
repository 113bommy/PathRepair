#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<int> all;
int main() {
  all.clear();
  int n, m;
  cin >> n >> m;
  int tmp;
  all.assign(m, 0);
  getchar();
  for (int i = (0); i < (n); i++) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int ff = 1;
    while (ss >> tmp) {
      if (ff == 1) {
        ff = 0;
        continue;
      }
      all[tmp - 1] = 1;
    }
  }
  bool flag = true;
  for (int i = (0); i < (m); i++) {
    if (all[i] == 0) {
      flag = false;
      break;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
