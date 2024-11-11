#include <bits/stdc++.h>
using namespace std;
vector<int> myv, vv[110001];
int n, m, ta, tb;
bool flag;
int main() {
  srand((unsigned(time(NULL))));
  cin >> n >> m;
  myv.clear();
  for (int i = 1; i <= n; i++) {
    myv.push_back(i);
    vv[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    cin >> ta >> tb;
    vv[ta].push_back(tb);
    vv[tb].push_back(ta);
  }
  bool tk = false;
  for (int i = 0; i < 500; i++) {
    random_shuffle(myv.begin(), myv.end());
    flag = true;
    for (int j = 0; j < m && flag; j++) {
      ta = myv[j];
      tb = myv[(j + 1) % n];
      for (int k = 0; k < vv[ta].size(); k++) {
        if (tb == vv[ta][k]) {
          flag = false;
        }
      }
    }
    if (flag == true) {
      for (int j = 0; j < m; j++) {
        cout << myv[j] << " " << myv[(j + 1) % n] << endl;
      }
      tk = true;
      break;
    }
  }
  if (!tk) {
    cout << "-1" << endl;
  }
  return 0;
}
