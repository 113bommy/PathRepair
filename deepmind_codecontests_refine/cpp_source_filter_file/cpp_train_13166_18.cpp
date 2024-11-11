#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
vector<int> pos[30];
string s;
long long int pre[100001];
int n;
long long int value[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 26; i++) cin >> value[i];
  cin >> s;
  for (int i = 0; i < int(s.size()); i++) {
    pre[i + 1] = pre[i] + value[s[i] - 'a'];
    pos[s[i] - 'a'].push_back(i);
  }
  long long int ans = 0;
  for (int i = 0; i < 26; i++) {
    map<long long int, int> sum;
    char aux = i + 'a';
    for (int j = 0; j < int(pos[i].size()); j++) {
      int atual = pos[i][j];
      ans += sum[pre[atual - 1]];
      sum[pre[atual]]++;
    }
  }
  cout << ans << "\n";
  return 0;
}
