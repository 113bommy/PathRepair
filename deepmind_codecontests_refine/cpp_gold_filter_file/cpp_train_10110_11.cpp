#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e18;
int cnt[1000];
double EE = 0.001;
int main() {
  int n, m;
  float k;
  cin >> n >> m >> k;
  map<string, int> mapp;
  for (int i = 1; i <= n; i++) {
    string s;
    int x;
    cin >> s >> x;
    int kk = int((k + EE) * 100);
    int b = int(kk * x / 100);
    if (b >= 100) mapp[s] = b;
  }
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    if (mapp[s] < 100) mapp[s] = 0;
  }
  cout << mapp.size() << endl;
  map<string, int>::iterator it;
  for (it = mapp.begin(); it != mapp.end(); it++) {
    cout << (*it).first << " " << (*it).second << endl;
  }
  return 0;
}
