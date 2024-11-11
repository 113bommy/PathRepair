#include <bits/stdc++.h>
using namespace std;
const int N = 0;
int n, x, t;
string s;
vector<int> v;
int vis[10005];
int main() {
  scanf("%d", &t);
  while (t--) {
    cin >> n >> s;
    if (s.length() == 2 && s[0] == s[1]) {
      printf("NO\n");
      continue;
    }
    printf("YES\n2\n");
    cout << s[0] << " " << s.substr(1) << endl;
  }
  return 0;
}
