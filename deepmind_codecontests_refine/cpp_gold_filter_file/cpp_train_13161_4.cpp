#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  unsigned long long h1, h2;
  string s1, s2;
  cin >> s1 >> s2;
  vector<unsigned long long> h(s1.length());
  vector<unsigned long long> pows(s1.length());
  pows[0] = 1;
  for (int i = 1; i < pows.size(); ++i) pows[i] = pows[i - 1] * 31;
  h1 = h2 = 0;
  for (int i = 0; i < s2.length(); ++i) h2 += (s2[i] - 'a' + 1) * pows[i];
  h[0] = s1[0] - 'a' + 1;
  for (int i = 1; i < s1.length(); ++i) {
    h[i] = (s1[i] - 'a' + 1) * pows[i];
    h[i] += h[i - 1];
  }
  vector<int> pos;
  for (int i = 0; i < s1.length(); ++i) {
    h1 = (i > 0 ? h[i - 1] : 0) * 31;
    h1 += h[s1.length() - 1] - h[i];
    if (h1 == h2 * 31) pos.push_back(i);
  }
  cout << pos.size() << endl;
  for (int i = 0; i < pos.size(); ++i) cout << pos[i] + 1 << endl;
  return 0;
}
