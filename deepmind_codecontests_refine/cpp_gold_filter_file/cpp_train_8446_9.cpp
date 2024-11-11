#include <bits/stdc++.h>
using namespace std;
long long pow(long long a, long long b, long long m) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long temp = pow(a, b / 2, m);
  temp = ((temp % m) * (temp % m)) % m;
  if (b & 1) temp = ((temp % m) * (a % m)) % m;
  return temp;
}
long long string_to_num(string s) {
  stringstream num(s);
  long long x;
  num >> x;
  return x;
}
string num_to_string(long long n) {
  string s;
  while (n > 0) {
    s = char(n % 10 + '0') + s;
    n /= 10;
  }
  return ((s.length() == 0) ? "0" : s);
}
const long long MOD = 998244353;
const long long mod = 1e9 + 7;
const long long N = 1e6 + 5;
string check[] = {"lios", "etr", "initis", "liala", "etra", "inites"};
long long cnt[6];
void solve() {
  string s;
  getline(cin, s);
  vector<string> arr;
  stringstream sss(s);
  string temp;
  while (sss >> temp) {
    arr.push_back(temp);
  }
  for (long long i = 0; i < arr.size(); i++) {
    string curr = arr[i];
    for (long long j = 0; j < 6; j++) {
      string temp = check[j];
      long long k = temp.size() - 1;
      long long kk = curr.size() - 1;
      while (k >= 0) {
        if (temp[k] == curr[kk]) {
          kk--;
          k--;
        } else {
          break;
        }
      }
      if (k == -1) {
        arr[i] = temp;
        break;
      }
    }
  }
  bool okk1 = false, okk2 = false;
  for (long long i = 0; i < arr.size(); i++) {
    bool okk = false;
    for (long long j = 0; j < 6; j++) {
      if (arr[i] == check[j]) {
        okk = true;
        cnt[j]++;
        if (j < 3 && cnt[j]) {
          okk1 = true;
        }
        if (j >= 3 && cnt[j]) {
          okk2 = true;
        }
      }
    }
    if (!okk) {
      cout << "NO" << '\n';
      return;
    }
  }
  if (arr.size() == 1) {
    cout << "YES" << '\n';
    return;
  }
  if (okk2 && okk1) {
    cout << "NO" << '\n';
    return;
  }
  if (okk1) {
    long long adj = 0;
    while (adj < arr.size()) {
      if (arr[adj] == "lios") {
        adj++;
      } else {
        break;
      }
    }
    long long noun = adj, cnt = 0;
    while (noun < arr.size()) {
      if (arr[noun] == "etr") {
        noun++;
        cnt++;
      } else {
        break;
      }
    }
    if (cnt != 1) {
      cout << "NO" << '\n';
      return;
    }
    long long verb = noun;
    while (verb < arr.size()) {
      if (arr[verb] == "initis") {
        verb++;
      } else {
        break;
      }
    }
    if (verb == arr.size()) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  if (okk2) {
    long long adj = 0;
    while (adj < arr.size()) {
      if (arr[adj] == "liala") {
        adj++;
      } else {
        break;
      }
    }
    long long noun = adj, cnt = 0;
    while (noun < arr.size()) {
      if (arr[noun] == "etra") {
        noun++;
        cnt++;
      } else {
        break;
      }
    }
    if (cnt != 1) {
      cout << "NO" << '\n';
      return;
    }
    long long verb = noun;
    while (verb < arr.size()) {
      if (arr[verb] == "inites") {
        verb++;
      } else {
        break;
      }
    }
    if (verb == arr.size()) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
int32_t main() {
  long long t = 1;
  for (long long T = 1; T <= t; T++) {
    solve();
  }
}
