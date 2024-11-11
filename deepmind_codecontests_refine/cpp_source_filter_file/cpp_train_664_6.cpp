#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5, INF = 1e18 + 1;
long long a, n, m, i, j, k;
string s1, s2, answer, s3;
int main() {
  cin >> n;
  s2 = "<3";
  s1 += s2;
  for (i = 0; i < n; ++i) {
    string s0;
    cin >> s0;
    s1 += s0;
    s1 += s2;
  }
  j = 0;
  cin >> s3;
  for (i = 0; i < s1.size(); ++i) {
    while (j < s3.size() && s3[j] != s1[i]) {
      j++;
    }
    if (j > s3.size()) {
      break;
    }
    j++;
  }
  if (i != s1.size()) {
    answer = "no";
  } else {
    answer = "yes";
  }
  cout << answer;
}
