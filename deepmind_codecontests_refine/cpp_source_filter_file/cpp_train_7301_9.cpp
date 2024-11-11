#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& x);
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& x);
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v);
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v);
template <typename S, typename T>
ostream& operator<<(ostream& os, const unordered_map<S, T>& v);
vector<long long> readvec(long long length, long long off = 0);
long long k;
long long prev_multiple_of_i(long long i) { return (i / k) * k; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n_flowers, n_people, n_schema;
  cin >> n_flowers >> k >> n_people >> n_schema;
  vector<long long> v = readvec(n_flowers);
  vector<long long> S = readvec(n_schema);
  long long can_delete = n_flowers - n_people * k;
  vector<long long> targets(6 * 1e5);
  for (long long x : S) targets[x]++;
  vector<long long> counts(6 * 1e5);
  long long redundant = 0;
  long long l = 0;
  long long r = -1;
  while (true) {
    r++;
    if (r >= n_flowers) goto fail;
    counts[v[r]]++;
    if (counts[v[r]] > targets[v[r]]) redundant++;
    long long non_redundant = (r - l + 1) - redundant;
    if (non_redundant >= n_schema) break;
  }
  while (targets[v[l]] == 0) {
    l++;
    if (l >= n_flowers) goto fail;
    redundant--;
  }
  while (true) {
    long long p = prev_multiple_of_i(l) + k - 1;
    long long need_to_del = max(r - p, 0LL);
    if (can_delete >= need_to_del &&
        (l - prev_multiple_of_i(l) + redundant) >= need_to_del) {
      cout << need_to_del << endl;
      long long pos = prev_multiple_of_i(l);
      while (need_to_del > 0) {
        if (pos < l) {
          cout << pos + 1 << " ";
          need_to_del--;
        } else {
          if (counts[v[pos]] >= targets[v[pos]]) {
            cout << pos + 1 << " ";
            counts[v[pos]]--;
            need_to_del--;
          }
        }
        pos++;
      }
      cout << endl;
      return 0;
    }
    counts[v[l]]--;
    if (counts[v[l]] >= targets[v[l]]) redundant--;
    while (counts[v[l]] < targets[v[l]]) {
      r++;
      if (r >= n_flowers) goto fail;
      if (counts[v[r]] >= targets[v[r]]) redundant++;
      counts[v[r]]++;
    }
    l++;
    if (l >= n_flowers) goto fail;
    while (targets[v[l]] == 0) {
      l++;
      if (l >= n_flowers) goto fail;
      redundant--;
    }
  }
fail:
  cout << -1 << endl;
}
template <typename S, typename T>
ostream& operator<<(ostream& os, const unordered_map<S, T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << "]";
  return os;
}
template <typename S, typename T>
ostream& operator<<(ostream& os, const map<S, T>& v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << "}";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << "]";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << "]";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << "]";
  return os;
}
template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& x) {
  os << "(" << x.first << ", " << x.second << ")";
  return os;
}
vector<long long> readvec(long long length, long long off) {
  vector<long long> v;
  for (long long i = 0; i < length; i++) {
    long long x;
    cin >> x;
    v.push_back(x + off);
  }
  return v;
}
