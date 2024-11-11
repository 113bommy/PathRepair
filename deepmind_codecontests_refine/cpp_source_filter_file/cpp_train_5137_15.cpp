#include <bits/stdc++.h>
using namespace std;
void solve() {
  string a, b;
  cin >> a >> b;
  int la, lb;
  la = a.size();
  lb = b.size();
  vector<int> s;
  for (int i = 1; i < (max(la, lb)); i++) {
    if (la % i == 0 && lb % i == 0) {
      s.push_back(i);
    }
  }
  int cnt = 0;
  for (int j = 0; j < s.size(); j++) {
    int k = s[j];
    string temp = "";
    for (int l = 0; l < k; l++) {
      temp += a[l];
    }
    string t1 = "", t2 = "";
    int div1 = la / k, div2 = lb / k;
    for (int m = 1; m <= div1; m++) {
      t1 += temp;
    }
    for (int m = 1; m <= div2; m++) {
      t2 += temp;
    }
    int flag = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != t1[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) continue;
    for (int i = 0; i < b.size(); i++) {
      if (b[i] != t2[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) continue;
    cnt++;
  }
  cout << cnt << endl;
}
int main() { solve(); }
