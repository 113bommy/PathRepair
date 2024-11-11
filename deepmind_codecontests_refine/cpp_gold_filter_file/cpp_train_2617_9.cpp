#include <bits/stdc++.h>
using namespace std;
int bs(vector<int> &v, int num) {
  int s = 0;
  int n = v.size();
  if (v[s] > num) return -1;
  if (v[s + n - 1] <= num) return (s + n - 1);
  int l = s;
  int r = s + n - 1;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    int val = v[mid];
    if (num < val)
      r = mid;
    else
      l = mid;
  }
  if (v[r] <= num) l = r;
  return l;
}
int get_cnt(vector<int> &v, int l, int r) {
  int pos_1 = bs(v, l - 1);
  int pos_2 = bs(v, r);
  if (pos_2 == -1)
    return 0;
  else
    return (pos_2 - pos_1);
}
long long int get_min(vector<int> &v, int A, int B, int l, int r) {
  long long int cnt = (long long int)(get_cnt(v, l, r));
  if (cnt == 0)
    return A;
  else {
    long long int n_d = (long long int)B * cnt * (long long int)(r - l + 1);
    if (l == r) return n_d;
    long long int s_1 = get_min(v, A, B, l, l + (r - l + 1) / 2 - 1);
    long long int s_2 = get_min(v, A, B, l + (r - l + 1) / 2, r);
    s_1 += s_2;
    return (n_d > s_1 ? s_1 : n_d);
  }
}
int main() {
  int n, k, A, B;
  cin >> n >> k >> A >> B;
  vector<int> v;
  v.clear();
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    v.push_back(c);
  }
  sort(v.begin(), v.end());
  cout << get_min(v, A, B, 1, 1 << n) << endl;
  return 0;
}
