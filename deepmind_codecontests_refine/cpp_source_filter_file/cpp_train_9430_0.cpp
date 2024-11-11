#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first)
    return a.second > b.second;
  else
    return a.first < b.first;
}
unsigned long long fact(unsigned long long n) {
  if (n == 1 || n == 0)
    return 1;
  else
    return n * fact(n - 1);
}
bool compp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}
vector<int> prime(20012, 1);
void preprocessing() {
  prime[0] = 0, prime[1] = 0;
  for (int i = 2; i * i <= 20012; i++) {
    if (prime[i] == 1) {
      for (int j = i * i; j <= 20012; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (int i = 0; i < prime.size(); i++)
    if (prime[i] != 0) prime[i] = i;
  sort(prime.begin(), prime.end());
  vector<int>::iterator r;
  for (auto i = prime.begin(); i != prime.end(); ++i) {
    if (*(i + 1) != 0) {
      r = i + 1;
      break;
    }
  }
  prime.erase(prime.begin(), r);
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first != b.first)
    return a.first > b.first;
  else
    return a.second < b.second;
}
string bin(unsigned long long n) {
  string ans;
  while (n) {
    ans.append(to_string(n % 2));
    n /= 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (a % b == 0)
    return b;
  else
    return (gcd(b, a % b));
}
bool perf(string s) {
  int cnt = 0;
  for (int i = s.size() - 1; i >= s.size() - 7; i--)
    if (s[i] == '0') cnt++;
  if (cnt == 6)
    return true;
  else
    return false;
}
int binary(vector<int> v, int k) {
  int lo = 0, hi = v.size() - 1, ans;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (v[mid] > k) {
      ans = mid + 1;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  return ans;
}
int main() {
  string s1, s2, s3;
  getline(cin, s1);
  getline(cin, s2);
  getline(cin, s3);
  int cnt = 0;
  bool h = true;
  for (auto i : s1)
    if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') cnt++;
  if (cnt != 5) h = false;
  if (h) {
    cnt = 0;
    for (auto i : s2)
      if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') cnt++;
    if (cnt != 7) h = false;
    if (h) {
      cnt = 0;
      for (auto i : s1)
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') cnt++;
      if (cnt != 5) h = false;
    }
  }
  h ? cout << "YES" : cout << "NO";
  return 0;
}
