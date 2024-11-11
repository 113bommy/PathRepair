#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
inline long long getPow(long long a, long long b) {
  long long res = 1, tp = a;
  while (b) {
    if (b & 1ll) {
      res *= tp;
    }
    tp *= tp;
    b >>= 1ll;
  }
  return res;
}
inline int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
void ok() {
  puts("YES");
  exit(0);
}
void no() {
  puts("NO");
  exit(0);
}
long long xx[] = {-1, 1, 0, 0};
long long yy[] = {0, 0, -1, 1};
bool cmp1(pair<pair<long long, long long>, long long> a,
          pair<pair<long long, long long>, long long> b) {
  return a.first.first - a.first.second > b.first.first - b.first.second;
}
bool cmp2(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first > b.first;
}
bool cmp3(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second > b.second;
}
int main() {
  long long n = nxt(), x = nxt(), y = nxt();
  vector<pair<pair<long long, long long>, long long> > arr(n);
  for (int i = 0; i < n; i++) {
    arr[i].first.first = nxt();
    arr[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    arr[i].first.second = nxt();
  }
  sort(arr.begin(), arr.end(), cmp1);
  vector<long long> ans_1;
  vector<long long> ans_2;
  long long sum = 0;
  for (int i = x; i < n - y; i++) {
    vector<pair<long long, long long> > te_1;
    vector<pair<long long, long long> > te_2;
    for (int j = 0; j < i; j++) {
      te_1.push_back({arr[j].first.first, arr[j].second});
    }
    for (int j = i; j < n; j++) {
      te_2.push_back({arr[j].first.second, arr[j].second});
    }
    sort(te_1.begin(), te_1.end(), cmp2);
    sort(te_2.begin(), te_2.end(), cmp2);
    long long cur_sum = 0;
    for (int j = 0; j < x; j++) {
      cur_sum += te_1[j].first;
    }
    for (int j = 0; j < y; j++) {
      cur_sum += te_2[j].first;
    }
    if (cur_sum > sum) {
      sum = cur_sum;
      ans_1.clear();
      ans_2.clear();
      for (int j = 0; j < x; j++) {
        ans_1.push_back(te_1[j].second + 1);
      }
      for (int j = 0; j < y; j++) {
        ans_2.push_back(te_2[j].second + 1);
      }
    }
  }
  cout << sum << endl;
  for (auto x : ans_1) {
    cout << x << " ";
  }
  cout << endl;
  for (auto x : ans_2) {
    cout << x << " ";
  }
  return 0;
}
