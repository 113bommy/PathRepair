#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long int> v[5004];
vector<unsigned long long int>::iterator it;
set<unsigned long long int> s;
set<unsigned long long int>::iterator iter;
bool check[100005];
int main() {
  unsigned long long int n = 0, m = 0, x = 0, res = 0, i = 0, j = 0, flag = 0;
  string s;
  cin >> n;
  for (unsigned long long int i = 1; i < n + 1; i++) {
    cin >> s;
    if (s[0] == 'X' && s[2] == '+' || s[0] == '+') {
      res++;
    } else {
      res--;
    }
  }
  cout << res << "\n";
  return 0;
}
