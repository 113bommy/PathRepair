#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
long long res = 0;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); ++i) v.push_back(s[i] - 48);
  for (int i = 0; i < v.size(); ++i)
    if (v[i] % 4 == 0) res++;
  for (int i = 1; i < v.size(); ++i)
    if ((v[i - 1] * 10 + v[i]) % 4 == 0) res += i;
  cout << res;
}
