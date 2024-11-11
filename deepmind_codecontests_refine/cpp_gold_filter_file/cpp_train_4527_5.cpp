#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 5;
string a[MAX];
int check[MAX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int tmp = n * 3 - 1;
  memset(check, 0, sizeof(check));
  string s, temp;
  int i = 0;
  while (tmp--) {
    cin >> s;
    if (s != "**") temp += s;
    if (s == "**") {
      a[i] = temp;
      temp = "";
      i++;
    }
  }
  a[i] = temp;
  int dem = 0;
  for (int i = 0; i < n; i++) {
    if (!check[i]) {
      dem++;
      string zd = a[i];
      stringstream ss;
      ss.str("");
      ss << zd[1] << zd[3] << zd[0] << zd[2];
      string nid = ss.str();
      ss.str("");
      ss << nid[1] << nid[3] << nid[0] << nid[2];
      string ond = ss.str();
      ss.str("");
      ss << ond[1] << ond[3] << ond[0] << ond[2];
      string twd = ss.str();
      check[i] = 1;
      for (int j = i + 1; j < n; j++) {
        if (zd == a[j] || nid == a[j] || ond == a[j] || twd == a[j]) {
          check[j] = 1;
        }
      }
    }
  }
  cout << dem;
  return 0;
}
