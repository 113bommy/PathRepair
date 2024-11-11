#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int a[1505];
int ps[1505];
int n;
int check(int sum) {
  int cnt = 0;
  int last_ending = -1;
  unordered_map<int, int> till_now;
  till_now[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (till_now.find(ps[i] - sum) != till_now.end()) {
      if (till_now[ps[i] - sum] >= last_ending) {
        last_ending = i;
        cnt++;
      }
    }
    till_now[ps[i]] = i;
  }
  return cnt;
}
void print(int sum) {
  int cnt = 0;
  int last_ending = -1;
  map<int, int> till_now;
  till_now[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (till_now.find(ps[i] - sum) != till_now.end()) {
      if (till_now[ps[i] - sum] >= last_ending) {
        last_ending = i;
        cout << till_now[ps[i] - sum] + 1 << " " << i << endl;
        cnt++;
      }
    }
    till_now[ps[i]] = i;
  }
  return;
}
unordered_map<int, int> freq;
int val[1500005];
int main() {
  auto start = high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int i, j, k, l, m, t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ps[i] = ps[i - 1] + a[i];
  }
  freq.reserve((1 << 21));
  for (i = 1; i <= n; i++) {
    int sum = 0;
    for (j = i; j <= n; j++) {
      sum += a[j];
      freq[sum]++;
    }
  }
  int cnt = 0;
  for (auto it : freq) {
    val[cnt++] = it.first;
  }
  sort(val, val + cnt, [](int a, int b) { return freq[a] > freq[b]; });
  int ans = 0;
  for (i = 0; i < 10; i++) {
    ans += val[i];
  }
  int an = 0;
  int id = -1;
  for (int i = 0; i < cnt; i++) {
    int sum = val[i];
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    if (duration.count() > 1900000) break;
    if (check(sum) > an) {
      an = check(sum);
      id = sum;
    }
  }
  cout << an << endl;
  print(id);
}
