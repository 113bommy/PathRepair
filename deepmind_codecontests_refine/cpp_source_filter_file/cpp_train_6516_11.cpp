#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long n, m, k;
string s;
void file() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  file();
  cin >> n;
  s = "aabbc";
  for (int i = 0; i < n; ++i) {
    if (k == 5) k = 0;
    cout << s[k];
    ++k;
  }
}
