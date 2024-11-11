#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s1, s2;
  cin >> s1 >> s2;
  long long h1, m1, h2, m2, h3 = 0, m3 = 0;
  h1 = stoi(s1.substr(0, 2));
  h2 = stoi(s2.substr(0, 2));
  m1 = stoi(s1.substr(3, 2));
  m2 = stoi(s2.substr(3, 2));
  long long a = h1, b = m1;
  while (a < h2) {
    m3 += 60 - b;
    a++;
    b = 0;
  }
  m3 += m2 - b;
  m3 /= 2;
  long long x = m3 / 60;
  m3 %= 60;
  h3 = h1 + x;
  m3 += m1;
  if (m3 > 59) h3++;
  m3 %= 60;
  if (h3 < 10) cout << "0";
  cout << h3 << ":";
  if (m3 < 10) cout << "0";
  cout << m3;
  return 0;
}
