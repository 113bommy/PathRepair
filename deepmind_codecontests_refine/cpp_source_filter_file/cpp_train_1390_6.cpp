#include <bits/stdc++.h>
using namespace std;
map<string, int> m1, m2, m3;
int N;
string A[60];
int sayi_bul(string s, int on) {
  if (s.size() == 1) return on * (s[0] - '0');
  return (s[s.size() - 1] - '0') * on +
         sayi_bul(s.substr(0, s.size() - 1), on * 10);
}
void read() {
  string s1, s2;
  string s3, s4;
  string str;
  int x;
  int a, b, c, d;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= (N * (N - 1)) / 2; i++) {
    cin >> str;
    x = str.find('-');
    s1 = str.substr(0, x);
    s2 = str.substr(x + 1, str.size() - x - 1);
    cin >> str;
    x = str.find(':');
    s3 = str.substr(0, x);
    s4 = str.substr(x + 1, str.size() - x - 1);
    a = sayi_bul(s3, 1);
    b = sayi_bul(s4, 1);
    if (a > b)
      c = 3, d = 0;
    else if (a == b)
      c = 1, d = 1;
    else
      c = 0, d = 3;
    m1[s1] += c;
    m1[s2] += d;
    m2[s1] += a - b;
    m2[s2] += b - a;
    m3[s1] += a;
    m3[s2] += b;
  }
}
bool cmp(const string a, const string b) {
  if (m1[a] == m1[b]) {
    if (m2[a] == m2[b]) {
      return m3[a] > m3[a];
    } else {
      return m2[a] > m2[b];
    }
  }
  return m1[a] > m1[b];
}
int main() {
  read();
  sort(A + 1, A + N + 1, cmp);
  sort(A + 1, A + N / 2 + 1);
  for (int i = 1; i <= N / 2; i++) cout << A[i] << endl;
  return 0;
}
