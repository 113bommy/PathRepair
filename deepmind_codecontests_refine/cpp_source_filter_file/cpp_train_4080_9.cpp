#include <bits/stdc++.h>
using namespace std;
vector<string> split(string s, string border);
long long SIZE_ARR = 200000;
void solve() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  vector<long long> a(n);
  for (long long i = 0; i < (n); i++) cin >> a[i];
  ;
  map<long long, long long> cnt_elements;
  for (long long i = 0; i < (n); i++) cnt_elements[a[i]]++;
  vector<long long> pr_cnt(SIZE_ARR + 2);
  for (long long i = 0; i < (pr_cnt.size() - 1); i++) {
    pr_cnt[i + 1] = pr_cnt[i] + cnt_elements[i];
  }
  long long ans = pow(10, 9);
  for (long long finish_el = 0; finish_el < (SIZE_ARR + 1); finish_el++) {
    long long ans_now = 0;
    long long l = finish_el, r = finish_el, step = 0, k_now = 0;
    while (l <= SIZE_ARR) {
      ans_now += step * (pr_cnt[r + 1] - pr_cnt[l]);
      k_now += pr_cnt[r + 1] - pr_cnt[l];
      if (k_now >= k) {
        ans_now -= step * (k_now - k);
        break;
      }
      step++;
      l = l * 2;
      r = min(r * 2 + 1, SIZE_ARR);
    }
    if (k_now >= k) ans = min(ans, ans_now);
  }
  cout << ans;
}
signed main(signed argc, char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.setf(cout.fixed);
  cout.precision(10);
  if (argc > 1 && (string)argv[1] == "file") {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long number_sample = 1;
    do {
      cout << "Sample #" << number_sample << ":" << '\n';
      cerr << "Sample #" << number_sample << ":" << '\n';
      solve();
      number_sample++;
      cout << '\n';
      cerr << '\n';
    } while (!cin.eof());
  } else {
    cerr.clear(ios_base::badbit);
    solve();
  }
}
vector<string> split(string s, string border) {
  vector<string> ans;
  long long pos_end;
  while ((pos_end = s.find(border)) != string::npos) {
    if (pos_end) ans.push_back(s.substr(0, pos_end));
    s = s.substr(pos_end + border.size());
  }
  return ans;
}
