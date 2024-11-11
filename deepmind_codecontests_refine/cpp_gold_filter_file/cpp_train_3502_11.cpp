#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265359;
const long long int Maxi = 1e18;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, i, j, l, k = 0, p = 0, s = 0, t = 1, x, y, z, r, c;
  long long a[100005] = {0};
  map<string, string> mp;
  cin >> n >> m;
  string s1, s2;
  while (n--) {
    cin >> s1 >> s2;
    mp[s2] = s1;
  }
  while (m--) {
    cin >> s1 >> s2;
    char s3[100];
    i = 0;
    while (i < 100) s3[i] = '\0', i++;
    for (i = 0; i < s2.size() - 1; i++) s3[i] = s2[i];
    cout << s1 << " " << s2 << " #" << mp[s3] << endl;
  }
  return 0;
}
