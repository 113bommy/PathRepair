#include <bits/stdc++.h>
using namespace std;
bool cmp1(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
void showvd(vector<double> v) {
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << " " << endl;
}
void showvi(vector<int> v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
void showvl(vector<long long> v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
void showvp(vector<pair<int, int> > v) {
  for (int i = 0; i < v.size(); i++)
    cout << v[i].first << " " << v[i].second << endl;
}
long long fastpower(long long a, long long n) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans = (ans * a);
    a = (a * a);
    n = n >> 1;
  }
  return ans;
}
int prime[10000001];
void SOE() {
  for (int i = 1; i <= 10000000; i++) prime[i] = i;
  for (int p = 2; p * p <= 10000000; p++) {
    if (prime[p] == p) {
      for (int i = p * p; i <= 10000000; i += p) {
        if (prime[i] == i) prime[i] = p;
      }
    }
  }
}
void factor(int n) {
  if (n == 1) return;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n = n / i;
      }
    }
  }
}
void solve() {
  int n, len;
  cin >> n >> len;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int k;
  cin >> k;
  long long sum_pos = 0, sum_neg = 0, sum = 0;
  multiset<long long> pos, neg;
  multiset<long long, greater<long long> > pos1, neg1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    sum += v[i];
    if (v[i] >= 0 && k) {
      if (pos.size() < k) {
        pos.insert(v[i]);
        sum_pos += v[i];
      } else {
        long long x = (*pos.begin());
        if (x < v[i]) {
          pos.erase(pos.find(x));
          sum_pos -= x;
          pos.insert(v[i]);
          sum_pos += v[i];
          pos1.insert(x);
        } else
          pos1.insert(v[i]);
      }
    } else if (k) {
      if (neg.size() < k) {
        neg.insert(v[i]);
        sum_neg += v[i];
      } else {
        long long x = (*neg.begin());
        if (x > v[i]) {
          neg.erase(neg.find(x));
          sum_neg -= x;
          neg.insert(v[i]);
          sum_neg += v[i];
          neg1.insert(x);
        } else
          neg1.insert(v[i]);
      }
    }
    if (i >= len) {
      sum -= v[i - len];
      if (v[i - len] >= 0 && k) {
        if (pos.find(v[i - len]) != pos.end()) {
          pos.erase(pos.find(v[i - len]));
          sum_pos -= v[i - len];
          if (pos1.size() > 0) {
            int y = (*pos1.begin());
            pos1.erase(pos1.find(y));
            pos.insert(y);
            sum_pos += y;
          }
        } else if (pos1.find(v[i - len]) != pos1.end())
          pos1.erase(pos1.find(v[i - len]));
      } else if (k) {
        if (neg.find(v[i - len]) != neg.end()) {
          neg.erase(neg.find(v[i - len]));
          sum_neg -= v[i - len];
          if (neg1.size() > 0) {
            int y = (*neg1.begin());
            neg1.erase(neg1.find(y));
            neg.insert(y);
            sum_neg += y;
          }
        } else if (neg1.find(v[i - len]) != neg1.end())
          neg1.erase(neg1.find(v[i - len]));
      }
    }
    if (i >= len - 1) {
      if (sum < 0)
        ans = max(ans, abs(sum - 2 * sum_pos));
      else if (sum > 0)
        ans = max(ans, sum + abs(2 * sum_neg));
      else
        ans = max(ans, 2 * (max(sum_pos, abs(sum_neg))));
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
