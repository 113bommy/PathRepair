#include <bits/stdc++.h>
using namespace std;
int x;
string str;
int f1(vector<int> ci, vector<int> ji);
bool kill1();
bool kill2(vector<int> ciel, vector<int> jiroa);
int n, m;
vector<int> ciel, jiroa, jirod;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> str >> x;
    if (str == "DEF") {
      jirod.push_back(x);
    } else {
      jiroa.push_back(x);
    }
  }
  for (int i = 1; i <= m; i++) {
    cin >> x;
    ciel.push_back(x);
  }
  sort(jiroa.begin(), jiroa.end());
  sort(jirod.begin(), jirod.end());
  sort(ciel.begin(), ciel.end());
  int ans1 = f1(ciel, jiroa);
  bool bl1 = kill1();
  int ans2;
  if (bl1 == 1) {
    bool bl2 = kill2(ciel, jiroa);
    if (bl2 == 1) {
      ans2 = 0;
      for (int i = 0; i < ciel.size(); i++) {
        ans2 += ciel[i];
      }
      for (int i = 0; i < jiroa.size(); i++) {
        ans2 -= jiroa[i];
      }
    }
  }
  cout << max(ans1, ans2) << endl;
  return 0;
}
int f1(vector<int> ci, vector<int> ji) {
  int maxans = 0;
  for (int i = 1; i <= ji.size() && i <= ci.size(); i++) {
    int ans = 0;
    for (int j = 0; j < i; j++) {
      if (ji[j] <= ci[ci.size() - i + j]) {
        ans += ci[ci.size() - i + j] - ji[j];
      } else {
        ans = 0;
        break;
      }
    }
    maxans = max(ans, maxans);
  }
  return maxans;
}
bool kill1() {
  for (int i = 0; i < jirod.size(); i++) {
    bool ok = 0;
    for (int j = 0; j < ciel.size(); j++) {
      if (ciel[j] > jirod[i]) {
        ciel.erase(ciel.begin() + j);
        ok = 1;
        break;
      }
    }
    if (ok == 0) {
      return 0;
    }
  }
  return 1;
}
bool kill2(vector<int> ciel, vector<int> jiroa) {
  for (int i = 0; i < jiroa.size(); i++) {
    bool ok = 0;
    for (int j = 0; j < ciel.size(); j++) {
      if (ciel[j] >= jiroa[i]) {
        ciel.erase(ciel.begin() + j);
        ok = 1;
        break;
      }
    }
    if (ok == 0) {
      return 0;
    }
  }
  return 1;
}
