#include <bits/stdc++.h>
using namespace std;
string sub(string x, long n) {
  stringstream s;
  for (int i = 0; i < x.size(); i++) {
    int k = x.size() - i - 1;
    if ((1 << k) & n) {
      s << x[k];
    }
  }
  return s.str();
}
bool check(string s) {
  int n = s.size();
  for (size_t i = 0; i < n / 2; ++i) {
    if (s[i] != s[s.size() - i - 1]) return false;
  }
  return true;
}
int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  long N = (1 << s.size());
  long i = 1;
  vector<string> v;
  while (i++ < N) {
    string temp = sub(s, i);
    if (check(temp)) v.push_back(temp);
  }
  sort(v.begin(), v.end());
  cout << v.back() << endl;
  return 0;
}
