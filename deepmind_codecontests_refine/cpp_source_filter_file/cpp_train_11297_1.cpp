#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const int inf = 1 << 30;
long long pw(long long b, long long p) {
  if (!p) return 1;
  long long sq = pw(b, p / 2);
  sq *= sq;
  if (p % 2) sq *= b;
  return sq;
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long sd(long long x) { return x < 10 ? x : x % 10 + sd(x / 10); }
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
int len_of_number(long long n) {
  long long temp = n;
  int cnt = 0;
  while (temp) {
    cnt++;
    temp /= 10;
  }
  return cnt;
}
string regulrize(string n) {
  int sz = n.size();
  char chars[] = ",;_";
  for (int i = 0; i < 3; i++)
    n.erase(remove(n.begin(), n.end(), chars[i]), n.end());
  for (int i = 0; i < sz; i++)
    if (n[i] >= 65 && n[i] <= 90) n[i] += 32;
  return n;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<string> a;
  string v, temp;
  int n, flag = 0;
  for (int i = 0; i < 3; i++) cin >> v, a.push_back(regulrize(v));
  sort((a).begin(), (a).end());
  vector<string> test, students;
  do {
    temp = "";
    for (int i = 0; i < 3; i++) temp += (a[i]);
    test.push_back(temp);
  } while (next_permutation((a).begin(), (a).end()));
  int sz = (int)(test).size();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    students.push_back(regulrize(temp));
  }
  for (int i = 0; i < n; i++) {
    flag = 0;
    for (int j = 0; j < 6; j++) {
      if (test[j] == students[i]) {
        cout << "ACC" << endl;
        flag++;
        break;
      }
    }
    if (!flag) cout << "WA" << endl;
  }
  return 0;
}
