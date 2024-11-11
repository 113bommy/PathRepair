#include <bits/stdc++.h>
using namespace std;
void ini() {}
long long int a[100001];
int main() {
  ini();
  string s, t = "  ", ans;
  cin >> s;
  long long int flag, h = 0;
  stack<char> st;
  for (long long int i = (long long int)(0); i < (long long int)(s.size());
       i++) {
    long long int j;
    flag = 0;
    for (j = i; s[j] != '>'; j++) {
      if (s[j] == '/') {
        h--;
        flag = 1;
      }
      ans.push_back(s[j]);
    }
    ans.push_back('>');
    i = j;
    for (long long int i = (long long int)(0); i < (long long int)(h); i++) {
      cout << t;
    }
    cout << ans << endl;
    ans.clear();
    if (flag != 1) {
      h++;
    }
  }
}
