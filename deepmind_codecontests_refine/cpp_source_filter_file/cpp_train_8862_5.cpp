#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
string IntToString(long long a) {
  char x[100];
  sprintf(x, "%lld", a);
  string s = x;
  return s;
}
long long StringToInt(string a) {
  char x[100];
  long long res;
  strcpy(x, a.c_str());
  sscanf(x, "%lld", &res);
  return res;
}
vector<string> split(string s, char b) {
  vector<string> ans;
  string temp = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == b) {
      ans.push_back(temp);
      temp = "";
    } else
      temp += s[i];
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    v.push_back(a);
  }
  int cnt = 1;
  int maxa = 0;
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    int pos1 = i;
    long long val = v[i] + 5;
    auto it = lower_bound(v.begin(), v.end(), val);
    int pos2 = it - v.begin();
    cnt = pos2 - pos1 + 1;
    if (v[pos2] - v[pos1] > 5 or it == v.end()) cnt--;
    maxa = max(maxa, cnt);
  }
  cout << maxa;
  return 0;
}
