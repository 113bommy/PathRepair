#include <bits/stdc++.h>
using namespace std;
unsigned long long mearge(vector<unsigned long long> &v,
                          unsigned long long begin, unsigned long long mid,
                          unsigned long long end) {
  vector<unsigned long long> buf(end - begin + 1);
  unsigned long long inv = 0;
  unsigned long long b_pos = begin, e_pos = mid + 1, buf_pos = 0;
  while (b_pos <= mid && e_pos <= end) {
    if (v[b_pos] < v[e_pos])
      buf[buf_pos++] = v[b_pos++];
    else {
      buf[buf_pos++] = v[e_pos++];
      inv += mid - b_pos + 1;
    }
  }
  while (b_pos <= mid) buf[buf_pos++] = v[b_pos++];
  while (e_pos <= end) buf[buf_pos++] = v[e_pos++];
  copy(buf.begin(), buf.end(), v.begin() + begin);
  return inv;
}
unsigned long long mearge_sort(vector<unsigned long long> &v,
                               unsigned long long begin,
                               unsigned long long end) {
  unsigned long long inv = 0;
  if (begin != end) {
    unsigned long long mid = (begin + end) / 2;
    inv += mearge_sort(v, begin, mid);
    inv += mearge_sort(v, mid + 1, end);
    inv += mearge(v, begin, mid, end);
  }
  return inv;
}
int main(int argv, char **argc) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  unsigned long long n, m, total = 0;
  vector<pair<unsigned long long, unsigned long long>> v, v_curr;
  unsigned long long sec = 0;
  unsigned long long min = 2;
  unsigned long long max;
  unsigned long long curr;
  cin >> n >> m;
  v.reserve(n);
  for (unsigned long long i = 1; i <= n; ++i) {
    unsigned long long a;
    cin >> a;
    if (a) {
      v.push_back(make_pair(i, a));
      total += a;
    }
  }
  max = total + n;
  unsigned long long boxes, rem_men, curr_pos;
  while (max > min + 1) {
    curr = (max + min) / 2;
    if (curr <= v[v.size() - 1].first) {
      min = curr;
      continue;
    }
    boxes = 0;
    v_curr = v;
    for (unsigned long long rem_men = m; rem_men > 0 && boxes < total;
         --rem_men) {
      long long rem = (signed long long)curr -
                      (signed long long)v_curr[v_curr.size() - 1].first;
      boxes += rem;
      for (signed long long i = v_curr.size() - 1; i >= 0 && rem != 0; --i) {
        if (v_curr[i].second <= rem) {
          rem -= v_curr[i].second;
          v_curr.pop_back();
        } else {
          v_curr[i].second -= rem;
          rem = 0;
        }
      }
    }
    if (boxes > total)
      max = curr;
    else
      min = curr;
  }
  cout << max << '\n';
  return 0;
}
