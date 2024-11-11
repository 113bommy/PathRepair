#include <bits/stdc++.h>
using namespace std;
vector<string> v2;
vector<vector<string> > v1;
int stringToInt(string s) {
  int sum = 0;
  int l = s.length() - 1;
  for (int i = 0; i < s.length(); i++) {
    sum += (s[i] - 48) * pow(10.0, l--);
  }
  return sum;
}
void permute(string s, int l, int h) {
  int x;
  if (l == h) {
    v2.push_back(s);
  } else {
    for (int i = l; i < h; i++) {
      swap(s[l], s[i]);
      permute(s, l + 1, h);
      swap(s[l], s[i]);
    }
  }
}
int main() {
  int n, k, x;
  cin >> n >> k;
  string stringstream;
  char c[k];
  vector<string> v;
  for (int i = 0; i < n; i++) {
    cin >> stringstream;
    v.push_back(stringstream);
  }
  for (int i = 0; i < k; i++) c[i] = (i + 1) + 48;
  c[k] = 0;
  string s = c;
  permute(s, 0, k);
  vector<int> v3;
  int xx;
  int min = 99999;
  for (int i = 0; i < v2.size(); i++) {
    v3.clear();
    for (int j = 0; j < v.size(); j++) {
      char ch[k];
      for (int kk = 0; kk < k; kk++) ch[kk] = v[j][(v2[i][kk] - 48) - 1];
      ch[k] = 0;
      string pat = ch;
      xx = stringToInt(pat);
      v3.push_back(xx);
    }
    sort(v3.begin(), v3.end());
    if (v3[v3.size() - 1] - v3[0] < min) {
      min = v3[v3.size() - 1] - v3[0];
    }
  }
  cout << min << endl;
  return 0;
}
