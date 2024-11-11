#include <bits/stdc++.h>
using namespace std;
long long a, b, c, i = 0, j = 0, res, n;
pair<long long, char> q[1000000];
string s;
char w[100001];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> w[i];
    q[int(w[i])].first++;
    q[int(w[i])].second = w[i];
  }
  for (i = int('a'); i <= int('z'); i++) {
    for (j = 0; j < q[i].first; j++) cout << q[i].second;
  }
}
