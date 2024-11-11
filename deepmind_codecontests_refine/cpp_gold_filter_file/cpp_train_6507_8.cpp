#include <bits/stdc++.h>
const int MAX = 2e7 + 9;
const int mod = 1e9 + 7;
using namespace std;
bool prime[MAX];
vector<unsigned long long> seive() {
  for (int i = 2; i < MAX; i++) prime[i] = false;
  int k = 0;
  vector<unsigned long long> p;
  for (int i = 2; i * i < MAX; i++) {
    if (!prime[i]) {
      for (int j = 2 * i; j < MAX; j += i) prime[j] = true;
    }
  }
  for (int i = 2; i < MAX; i++) {
    if (!prime[i]) p.push_back(i);
  }
  return p;
}
unsigned long long mexp(unsigned long long a, unsigned long long b) {
  unsigned long long res = 1;
  while (b) {
    if (b % 2) {
      res = (res * a);
    }
    a = (a * a);
    b = b / 2;
  }
  return res;
}
int main() {
  string s;
  vector<string> v;
  int i = 0;
  while (getline(cin, s)) {
    v.push_back(s);
  }
  int mx = -1;
  for (int i = 0; i < v.size(); i++) {
    int l = v[i].size();
    mx = max(mx, l);
  }
  int tot = mx;
  for (int i = 0; i < tot + 2; i++) cout << '*';
  cout << "\n";
  int f = 1;
  for (int i = 0; i < v.size(); i++) {
    cout << '*';
    int l = v[i].size();
    int rem = tot - l;
    rem = rem / 2;
    if ((tot - l) % 2 != 0) {
      rem = rem + (f ^ 1);
      f = f ^ 1;
    }
    for (int j = 0; j < rem; j++) cout << " ";
    cout << v[i];
    for (int i = 0; i < tot - rem - l; i++) cout << " ";
    cout << '*';
    cout << "\n";
  }
  for (int i = 0; i < mx + 2; i++) cout << '*';
}
