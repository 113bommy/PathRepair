#include <bits/stdc++.h>
using namespace std;
map<string, bool> dis;
map<string, string> dis2;
int main() {
  int n;
  scanf("%d", &n);
  string str;
  string s[6] = {"red", "green", "blue", "orange", "yellow", "purple"};
  dis2[s[0]] = {"Reality"};
  dis2[s[1]] = {"Time"};
  dis2[s[2]] = {"Space"};
  dis2[s[3]] = {"Soul"};
  dis2[s[4]] = {"Mind"};
  dis2[s[5]] = {"Power"};
  for (int i = 0; i < n; i++) {
    cin >> str;
    dis[str] = true;
  }
  int cnt = 0;
  for (int i = 0; i < 6; i++) {
    if (!dis[s[i]]) cnt++;
  }
  printf("%d", cnt);
  for (int i = 0; i < 6; i++) {
    if (!dis[s[i]]) cout << dis2[s[i]] << endl;
  }
  return 0;
}
