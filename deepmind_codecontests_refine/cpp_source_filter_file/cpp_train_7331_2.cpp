#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> c;
int bolsa = 0;
void coef(int, int);
void signo(int id) {
  if (s[id] == '+')
    coef(id + 1, 1);
  else
    coef(id + 1, -1);
}
void inc(int id, int coef) {
  if (s[id] == '+') {
    bolsa += coef;
    id += 3;
    if (id < s.size()) signo(id);
  } else {
    id += 3;
    if (id < s.size()) signo(id);
  }
}
void coef(int id, int sig) {
  if (s[id] == '+' or s[id] == 'a') {
    c.push_back(1);
    inc(id, 1 * sig);
  } else {
    int j = id;
    int n = 0;
    while (j < s.size() and s[j] <= '9' and s[j] >= '0') {
      n = n * 10 + s[j] - '0';
      j++;
    }
    j++;
    c.push_back(n * sig);
    if (j < s.size()) inc(j, n * sig);
  }
}
int main() {
  int a;
  cin >> a >> s;
  coef(0, 1);
  sort(c.begin(), c.end());
  long long ans = 0;
  for (int i = (int)0; i < (int)c.size(); i++) {
    ans += a * c[i];
    a++;
  }
  ans += bolsa;
  cout << ans << endl;
  return 0;
}
