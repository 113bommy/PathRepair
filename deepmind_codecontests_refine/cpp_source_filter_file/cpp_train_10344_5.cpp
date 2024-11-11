#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  long long num = 1e5 + 3;
  long long pos[num];
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    pos[a] = i;
  }
  long long m;
  cin >> m;
  long long counta = 0, countb = 0;
  for (int j = 0; j < m; ++j) {
    long long b;
    cin >> b;
    counta += pos[b];
    countb += n - pos[b] + 1;
  }
  cout << counta << " " << countb;
}
