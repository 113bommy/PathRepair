#include <bits/stdc++.h>
using namespace std;
struct mhash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  uint64_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
#pragma warning(disable : 4996)
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) cout << i << " ";
  return os;
}
long long bp(long long A, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= A;
    A *= A;
    n >>= 1;
  }
  return res;
}
long long gcd(long long A, long long B) {
  while (B) {
    A %= B;
    swap(A, B);
  }
  return A;
}
long long lcm(long long A, long long B) { return A / gcd(A, B) * B; }
vector<int> zf(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
long long mod(long long A, long long B) { return ((A % B) + B) % B; }
void solve() {
  string n;
  cin >> n;
  int ans = (1 << 30);
  int len = (int)(n).size() - 1;
  if ((int)(n).size() > 1) {
    for (int i = 0; i < (int)((int)(n).size()); i++) {
      for (int j = 0; j < (int)((int)(n).size()); j++) {
        if (i != j) {
          string temp(n);
          int pos_value{};
          if ((int(temp[i] - '0') + 10 * int(temp[j] - '0')) % 25) continue;
          char cur = temp[j];
          temp.erase(temp.begin() + j);
          temp += cur;
          cur = temp[i - int(i > j)];
          temp.erase(temp.begin() + i - int(i > j));
          temp += cur;
          pos_value = (len - i) + (len - j) - 1;
          if (temp[0] == '0') {
            int to_add = -1;
            for (int k = 0; k < (int)((int)(n).size()); k++) {
              if (temp[k] != '0' && k != i && k != j) {
                to_add = k;
                break;
              }
            }
            cur = temp[to_add];
            temp.erase(temp.begin() + to_add);
            temp.insert(temp.begin(), cur);
            pos_value += to_add;
          }
          long long test = stoll(temp);
          if (i < j) pos_value++;
          ans = min(ans, pos_value);
        }
      }
    }
  }
  if (ans == (1 << 30)) ans = -1;
  cout << ans << "\n";
}
int main() {
  cout.tie(0);
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t = 1;
  for (int C = 1; C < (int)(t + 1); C++) {
    solve();
  }
}
