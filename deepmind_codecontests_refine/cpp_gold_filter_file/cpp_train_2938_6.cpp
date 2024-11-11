#include <bits/stdc++.h>
using namespace std;
vector<string> v1[110];
multiset<string> v2[110];
string ans = "";
int N;
void proses(string &str, int idx) {
  vector<int> tmp(26, 0);
  for (int i = 0; i < (idx - 1); i++) {
    tmp[ans[i] - 'a']++;
  }
  for (char u : str) {
    if (tmp[u - 'a'] == 0) {
      ans[idx - 1] = u;
      return;
    }
    tmp[u - 'a']--;
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) ans.push_back('a');
  cout << "? " << 1 << " " << N << endl;
  string str;
  fflush(stdout);
  for (int i = 0; i < (N * (N + 1)) / 2; i++) {
    cin >> str;
    sort(str.begin(), str.end());
    v1[(int)str.length()].push_back(str);
  }
  if (N == 1) {
    cout << "! " << v1[1][0] << endl;
    return 0;
  }
  cout << "? " << 2 << " " << N << endl;
  for (int i = 0; i < ((N - 1) * (N)) / 2; i++) {
    cin >> str;
    sort(str.begin(), str.end());
    v2[(int)str.length()].insert(str);
  }
  for (int i = 1; i <= N; i++) {
    for (string &u : v1[i]) {
      if (v2[i].find(u) == v2[i].end()) {
        proses(u, i);
      } else {
        v2[i].erase(v2[i].find(u));
      }
    }
  }
  cout << "! " << ans << endl;
  return 0;
}
