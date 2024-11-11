#include <bits/stdc++.h>
using namespace std;
bool Compare(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}
const int INF = 0x3f3f3f3f;
string tostring(long long int Number) {
  string String;
  ostringstream Convert;
  Convert << Number;
  String = Convert.str();
  return String;
}
long long int toint(string String) {
  stringstream Convert(String);
  long long int Number = 0;
  Convert >> Number;
  return Number;
}
int Lower_bound(vector<int> v, int k) {
  vector<int>::iterator low;
  low = lower_bound(v.begin(), v.end(), k);
  int lower;
  lower = (low - v.begin()) - 1;
  return lower;
}
int Upper_bound(vector<int> v, int k) {
  vector<int>::iterator up;
  up = upper_bound(v.begin(), v.end(), k);
  int upper;
  upper = (up - v.begin());
  return upper;
}
char pr[33] = {'!', '"',  '#', '$', '%', '&', '\'', '(', ')', '*', '+',
               ',', '-',  '.', '/', ':', ';', '<',  '=', '>', '?', '@',
               '[', '\\', ']', '^', '_', '`', '{',  '|', '}', '~', ' '};
bool pck(char ch) {
  for (int i = 0; i < 33; i++) {
    if (ch == pr[i]) return true;
  }
}
long long int bigmod(long long int b, long long int p, long long int m) {
  long long int x;
  if (p == 0) return 1 % m;
  x = bigmod(b, p / 2, m);
  x = (x * x) % m;
  if (p % 2 == 0)
    x = x;
  else
    x = (x * b) % m;
  return x;
}
bool status[100000005];
vector<int> Prime;
void sieve() {
  long long int i, j, N;
  N = 100000;
  long long int sq = sqrt(N);
  for (i = 4; i <= N; i += 2) status[i] = 1;
  for (i = 3; i <= sq; i += 2) {
    if (status[i] == 0) {
      for (j = i * i; j <= N; j += i) status[j] = 1;
    }
  }
  status[1] = 1;
  for (i = 1; i <= N; i++) {
    if (status[i] == 0) Prime.push_back(i);
  }
}
long long int ReverseI(long long int n) {
  long long int x = 0;
  while (n != 0) {
    x = x * 10 + n % 10;
    n = n / 10;
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string second;
  cin >> second;
  int i;
  for (i = 0; i < n; i++) {
    if (second[i] > second[i + 1]) {
      cout << "YES" << endl;
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
