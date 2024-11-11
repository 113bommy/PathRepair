#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167772160000")
template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T>
using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;
using namespace std;
const long long A1 = 999999929;
const long long B1 = 999999937;
const long long A2 = 1000000007;
const long long B2 = 1000000009;
struct Hash {
  long long a, b;
  string orig;
  Hash(const string& s) {
    a = 0;
    b = 0;
    orig = s;
    long long A = 1;
    long long B = 1;
    for (int i = (s.length() - 1); i >= (0); i--) {
      int c = s[i];
      a = (a + A * c) % B1;
      b = (b + B * c) % B2;
      A *= A1;
      B *= A2;
    }
  }
  bool eq(Hash other) { return a == other.a && b == other.b; }
};
struct Data {
  Hash h = Hash("");
  int len;
  Data(const string& s) {
    h = Hash(s);
    len = s.length();
  }
};
vector<Data> words;
long long prefSum[100000];
int n;
int totalLength = 0, spaceLength;
vector<Data> make(int start, int len) {
  vector<Data> v;
  int i = start;
  while (v.size() < len && i < n) {
    v.push_back(words[i]);
    i++;
  }
  return v;
}
bool eq(std::pair<int, int> a, std::pair<int, int> b) {
  if (a.second - a.first != b.second - b.first) return false;
  for (int i = (a.first); i < (a.second); i++) {
    if (!words[i].h.eq(words[i - a.first + b.first].h)) return false;
  }
  return true;
}
long long getSum(int from, int to) {
  long long ans = prefSum[to];
  if (from > 0) ans -= prefSum[from - 1];
  return ans;
}
bool isPossible(int len) {
  for (int s1 = (0); s1 < (n - len + 1); s1++) {
    for (int s2 = (s1 + len); s2 < (n - len + 1); s2++) {
      std::pair<int, int> a = {s1, s1 + len};
      std::pair<int, int> b = {s2, s2 + len};
      if (eq(a, b)) {
        return true;
      }
    }
  }
  return false;
}
int solve(int len) {
  int best = ((1LL << 31) - 1);
  for (int s1 = (0); s1 < (n - len + 1); s1++) {
    vector<int> starts;
    for (int s2 = (s1 + len); s2 < (n - len + 1); s2++) {
      std::pair<int, int> a = {s1, s1 + len};
      std::pair<int, int> b = {s2, s2 + len};
      if (eq(a, b)) {
        starts.push_back(s2);
        s2 = s2 + len - 1;
      }
    }
    if (starts.size() > 0) {
      std::pair<int, int> a = {s1, s1 + len};
      int delta = getSum(a.first, a.second - 1);
      delta += a.second - a.first;
      delta -= a.second - a.first + 1;
      for (auto e : starts) {
        std::pair<int, int> b = {e, e + len};
        delta += getSum(b.first, b.second - 1);
        delta += b.second - b.first;
        delta -= b.second - b.first + 1;
      }
      best = min(best, totalLength - delta);
    }
  }
  return best;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  spaceLength = n - 1;
  for (int i = (0); i < (n); i++) {
    string s;
    cin >> s;
    totalLength += s.length();
    words.push_back(Data(s));
  }
  prefSum[0] = words[0].len;
  for (int i = (1); i < (n); i++) {
    prefSum[i] = prefSum[i - 1] + words[i].len;
  }
  totalLength += spaceLength;
  int best = totalLength;
  for (int len = (1); len < (n / 2); len++) {
    best = min(best, solve(len));
  }
  cout << best << endl;
  return 0;
}
