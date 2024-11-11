#include <bits/stdc++.h>
using namespace std;
string s;
int cc[2][2];
int main() {
  cin >> s;
  long long ec = 0, oc = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    cc[s[i] - 'a'][i & 1]++;
    oc += cc[s[i] - 'a'][i & 1];
    ec += cc[s[i] - 'a'][~i & 1];
  }
  cout << ec << " " << oc << endl;
}
