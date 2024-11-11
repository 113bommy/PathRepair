#include <bits/stdc++.h>
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
using namespace std;
string ss[8] = {"vaporeon", "jolteon", "flareon", "espeon",
                "umbreon",  "leafeon", "glaceon", "sylveon"};
int main() {
  double st = clock();
  srand(time(NULL));
  int x;
  cin >> x;
  string s;
  cin >> s;
  int ar[8] = {0};
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < 8; j++) {
      if (s.size() == ss[j].size())
        for (int k = 0; k < ss[j].size(); k++) {
          if (s[i] != '.' && s[i] == ss[j][k] && i == k) {
            ar[j]++;
          }
        }
    }
  }
  int mx = 0;
  for (int i = 0; i < 8; i++) {
    if (s.size() == ss[i].size() && ar[mx] <= ar[i]) mx = i;
  }
  cout << ss[mx];
  return 0;
}
