#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
long long And, Or;
vector<long long> v;
void init() {
  cout << "and " << 1 << " " << 2 << endl;
  long long x;
  cin >> x;
  vector<int> first(32, 0), sec(32, 0);
  int index = 0;
  while (x) {
    if (x % 2) {
      first[index] = sec[index] = 1;
    }
    x /= 2;
    index++;
  }
  cout << "or " << 1 << " " << 2 << endl;
  cin >> x;
  index = 0;
  set<int> sus;
  while (x) {
    if (x % 2 && first[index] == 0) {
      sus.insert(index);
    }
    x /= 2;
    index++;
  }
  long long O13, O23;
  cout << "and " << 1 << " " << 3 << endl;
  cin >> O13;
  cout << "and " << 2 << " " << 3 << endl;
  cin >> O23;
  And = O23;
  index = 0;
  while (O13 || O23) {
    if (sus.count(index)) {
      if (O13 % 2) {
        first[index] = 1;
        sus.erase(index);
      } else if (O23 % 2) {
        sec[index] = 1;
        sus.erase(index);
      }
    }
    O13 /= 2;
    O23 /= 2;
    index++;
  }
  cout << "or " << 1 << " " << 3 << endl;
  cin >> O13;
  cout << "or " << 2 << " " << 3 << endl;
  cin >> O23;
  Or = O23;
  index = 0;
  while (O13 || O23) {
    if (sus.count(index)) {
      if (O13 % 2) {
        first[index] = 1;
        sus.erase(index);
      } else if (O23 % 2) {
        sec[index] = 1;
        sus.erase(index);
      }
    }
    O13 /= 2;
    O23 /= 2;
    index++;
  }
  long long num1 = 0, num2 = 0;
  for (int i = 0; i < 32; i++) {
    if (first[i]) {
      num1 += (1 << i);
    }
  }
  for (int i = 0; i < 32; i++) {
    if (sec[i]) {
      num2 += (1 << i);
    }
  }
  v.push_back(num1), v.push_back(num2);
}
void bin(long long num, vector<long long>& v) {
  int index = 0;
  while (num) {
    v[index] = num % 2;
    index++;
    num /= 2;
  }
}
void check() {
  vector<long long> lst(32, 0), AndV(32, 0), OrV(32, 0);
  long long Recent = 0;
  bin(v.back(), lst);
  bin(And, AndV);
  bin(Or, OrV);
  for (int i = 0; i < 32; i++) {
    if (lst[i]) {
      if (AndV[i]) Recent += (1 << i);
    } else {
      if (OrV[i]) Recent += (1 << i);
    }
  }
  v.push_back(Recent);
}
void solve() {
  int n, k;
  cin >> n >> k;
  init();
  check();
  for (int i = 4; i <= n; i++) {
    cout << "and " << i - 1 << " " << i << endl;
    cin >> And;
    cout << "or " << i - 1 << " " << i << endl;
    cin >> Or;
    check();
  }
  sort(v.begin(), v.end());
  cout << "finish " << v[k - 1] << endl;
}
int main() {
  int t = 1;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (t--) {
    solve();
  }
  return 0;
}
