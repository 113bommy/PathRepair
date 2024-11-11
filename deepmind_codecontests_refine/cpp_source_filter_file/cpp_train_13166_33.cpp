#include <bits/stdc++.h>
using namespace std;
int N[300];
int CH[256];
map<long long, int> M[256];
long long sum[100000];
bool used[30000];
int main() {
  for (int i = 0; i < 26; i++) {
    int k;
    cin >> k;
    CH['a' + i] = k;
  }
  string str;
  cin >> str;
  long long s = 0;
  int ans = 0;
  for (int i = 0; i < str.size(); i++) {
    ans += M[str[i]][s];
    s += CH[str[i]];
    sum[i] = s;
    M[str[i]][s]++;
  }
  cout << ans << endl;
  return 0;
}
