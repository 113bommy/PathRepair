#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "{" << p.first << "," << p.second << "}";
  return os;
}
const long long N = 3e5 + 5;
const long long oo = 1e9 + 7;
map<long long, long long> hah;
unordered_map<long long, long long> save;
pair<long long, long long> sz(long long bit) {
  pair<long long, long long> re = {40, 0};
  for (long long i = 0; i <= 40; i++) {
    if (bit & (1LL << i)) {
      re.first = min(re.first, i);
      re.second = max(re.second, i);
    }
  }
  return re;
}
long long gg(long long bit) {
  if (save[bit] != 0) {
    return save[bit] - 1;
  }
  long long ret = 0;
  pair<long long, long long> rng = sz(bit);
  priority_queue<long long> pq;
  for (long long i = rng.first; i <= rng.second; i++) {
    long long lo = bit & ((1LL << i) - 1);
    lo |= (bit >> i);
    if (lo & 1) lo ^= 1;
    if (bit != lo) pq.push(-(gg(lo)));
  }
  while (!pq.empty()) {
    if (-pq.top() == ret) {
      pq.pop();
      ret++;
    } else if (-pq.top() < ret) {
      pq.pop();
    } else
      break;
  }
  save[bit] = ret + 1;
  return ret;
}
void add(long long n) {
  long long p = 0;
  while (n % 2 == 0) {
    n /= 2;
    p++;
  }
  if (p) hah[2] |= 1LL << p;
  for (long long i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      long long p = 0;
      while (n % i == 0) {
        p++;
        n /= i;
      }
      hah[i] |= 1LL << p;
    }
  }
  if (n > 1) {
    hah[n] |= 1LL << 1;
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  while (n--) {
    long long x;
    cin >> x;
    add(x);
  }
  long long ans = 0;
  for (auto i : hah) {
    ans ^= gg(i.second);
  }
  cout << (ans ? "Mojtaba" : "Arpa");
}
