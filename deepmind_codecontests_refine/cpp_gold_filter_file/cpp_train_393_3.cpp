#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  size_t cnt=count(s.begin(), s.end(), '1');
  cout << min(cnt, s.size()-cnt)*2;
}
