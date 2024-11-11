#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
map<long long, pair<long long, long long> > kmap;
vector<pair<long long, long long> > num;
vector<long long> kind;
long long e[200050];
int ks;
bool cmp(pair<long long, long long> A, pair<long long, long long> B) {
  return A.first == B.first ? A.second > B.second : A.first > B.first;
}
bool cmp1(pair<long long, long long> A, pair<long long, long long> B) {
  return A.second > B.second;
}
int lowbits(int x) { return x & -x; }
long long getSum(long long x) {
  long long rs = 0;
  for (; x > 0; x -= lowbits(x)) {
    rs += e[x];
  }
  return rs;
}
void update(long long x, long long p) {
  for (; x <= ks; x += lowbits(x)) {
    e[x] += p;
  }
}
int getMid(long long x, long long l, long long r) {
  if (kind[r] > x) return -1;
  long long mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (kind[mid] <= x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    kmap.clear();
    for (long long i = 0, x, f; i < n; i++) {
      cin >> x >> f;
      if (kmap.count(x) == 0) {
        kmap[x] = make_pair(0, 0);
      }
      kmap[x].first++;
      kmap[x].second += f;
    }
    map<long long, pair<long long, long long> >::iterator kit;
    num.clear();
    for (kit = kmap.begin(); kit != kmap.end(); kit++) {
      num.push_back((kit->second));
    }
    sort(num.begin(), num.end(), cmp);
    long long tmp = 1e9 + 1;
    long long sum = 0;
    long long ns = num.size();
    kind.clear();
    for (long long i = 0; i < ns && tmp > 0; i++) {
      if (num[i].first < tmp) {
        sum += num[i].first;
        tmp = num[i].first;
        kind.push_back(num[i].first);
      } else {
        sum += (tmp - 1LL);
        kind.push_back(tmp - 1LL);
        tmp = tmp - 1LL;
      }
    }
    sort(num.begin(), num.end(), cmp1);
    ks = kind.size();
    for (int i = 0; i <= ks + 10; i++) {
      e[i] = 0;
    }
    for (int i = 1; i <= ks; i++) {
      update(i, 1);
    }
    int cnt = 0;
    long long ss = 0;
    for (int i = 0; i < ns && cnt < ks; i++) {
      int mid = getMid(num[i].first, 0, ks - 1) + 1;
      if (mid == -1 || getSum(ks) - getSum(mid - 1) <= 0) continue;
      int l = mid, r = ks;
      long long ori = getSum(mid - 1);
      while (l < r) {
        mid = (l + r) / 2;
        if (getSum(mid) - ori > 0) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      cnt++;
      ss += min(num[i].second, kind[l - 1]);
      update(l, -1);
    }
    cout << sum << " " << ss << endl;
  }
  return 0;
}
