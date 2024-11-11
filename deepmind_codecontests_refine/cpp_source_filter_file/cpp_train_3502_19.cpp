#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, m, flag = 0, cnt, cnt1 = 0;
  char name[20], name2[20], ip1[20];
  string ip2;
  scanf("%d %d", &n, &m);
  map<string, string> mp;
  for (i = 0; i < n; i++) {
    scanf("%s %s", name, ip1);
    mp[ip1] = name;
  }
  for (j = 0; j < m; j++) {
    scanf("%s", name2);
    cin >> ip2;
    ip2.pop_back();
    printf("%s", name2);
    cout << ip2;
    printf("; #%s\n", mp[ip2].c_str());
  }
}
