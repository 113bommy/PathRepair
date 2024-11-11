#include <bits/stdc++.h>
using namespace std;
long long n, i;
string s1, s2, s3, s4;
vector<long long> v;
map<long long, long long> m;
int main() {
  cin >> s1 >> s2;
  cin >> n;
  cout << s1 << " " << s2 << endl;
  for (i = 1; i <= n; i++) {
    cin >> s3 >> s4;
    if (s1 == s3) {
      cout << s4 << " " << s2 << endl;
      s1 = s4;
    } else {
      cout << s1 << " " << s4 << endl;
      s2 = s4;
    }
  }
  return 0;
}
