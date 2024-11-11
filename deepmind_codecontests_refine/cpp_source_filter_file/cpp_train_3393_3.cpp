#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> vec1, vec2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> vs;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vs.push_back(s);
  }
  int mini = INT_MAX;
  for (int i = 0; i < n; i++) {
    string s2 = vs[i];
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      string s3 = vs[j];
      while (s2 != s3) {
        cnt++;
        s3.push_back(s3[0]);
        s3.erase(s3.begin());
        if (cnt == 1e3) return cout << -1 << endl, 0;
      }
    }
    mini = min(cnt, mini);
  }
  cout << mini << endl;
  return 0;
}
