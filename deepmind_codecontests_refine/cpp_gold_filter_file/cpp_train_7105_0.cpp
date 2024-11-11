#include <bits/stdc++.h>
using namespace std;
long long int find_max_reverse(vector<long long int> a, long long int l,
                               long long int r, long long int sum_even,
                               long long int sum_odd);
long long int maximum(long long int a, long long int b, long long int c) {
  long long int max = (a < b) ? b : a;
  return ((max < c) ? c : max);
}
long long int find_max_reverse(vector<long long int> a) {
  long long int ma = 0;
  long long int benefit = 0;
  for (long long int i = 0; i < a.size() && i + 1 < a.size(); i += 2) {
    if (benefit + a[i + 1] - a[i] > 0) {
      benefit += a[i + 1] - a[i];
      ma = max(ma, benefit);
    } else
      benefit = 0;
  }
  benefit = 0;
  for (long long int i = 1; i < a.size() && i + 1 < a.size(); i += 2) {
    if (benefit + a[i] - a[i + 1] > 0) {
      benefit += a[i] - a[i + 1];
      ma = max(ma, benefit);
    } else
      benefit = 0;
  }
  return ma;
}
int main() {
  long long int n;
  cin >> n;
  vector<long long int> circle(n);
  vector<long long int> prefix_sum(n);
  vector<long long int> suffix_sum(n);
  for (long long int i = 0; i < n; i++) {
    long long int temp;
    cin >> circle[i];
  }
  prefix_sum[0] = circle[0];
  prefix_sum[1] = circle[1];
  suffix_sum[n - 1] = circle[n - 1];
  suffix_sum[n - 2] = circle[n - 2];
  for (long long int i = 2; i < circle.size(); i++) {
    prefix_sum[i] = prefix_sum[i - 2] + circle[i];
    suffix_sum[n - i - 1] = suffix_sum[n - i + 1] + circle[n - i - 1];
  }
  long long int ma;
  ma = suffix_sum[0];
  for (long long int i = 1; i < n; i++)
    ma = max(ma, prefix_sum[i - 1] + suffix_sum[i]);
  cout << ma << endl;
}
