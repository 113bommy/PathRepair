#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
template <typename T>
std::istream& operator>>(std::istream& input, std::pair<T, T>& data) {
  input >> data.first >> data.second;
  return input;
}
template <typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& data) {
  for (T& first : data) input >> first;
  return input;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const pair<T, T>& data) {
  output << "(" << data.first << "," << data.second << ")";
  return output;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const std::vector<T>& data) {
  for (const T& first : data) output << first << " ";
  return output;
}
std::ostream& operator<<(std::ostream& output, const __int128& first) {
  __int128 n = first;
  if (n == 0) {
    output << "0";
    return output;
  }
  if (n < 0) {
    n = -n;
    output << "-";
  }
  string s;
  while (n) {
    s += '0' + (n % 10);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
  return output;
}
long long div_up(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
long long div_down(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
long long math_mod(long long a, long long b) { return a - b * div_down(a, b); }
template <class T>
using V = vector<T>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
long long gcd(long long a, long long b) {
  while (b) {
    tie(a, b) = make_pair(b, a % b);
  }
  return a;
}
long long Bit(long long mask, long long bit) { return (mask >> bit) & 1; }
const long long N = 1e5 + 7, INF = 314000000;
long long m, n;
long long out_op[N], rem_op[N];
bool cand_end[N];
bool can_inf[N];
long long cost[N];
long long from[N];
vi in[N], op[N], to[N];
long long mn[N], mx[N];
long long dsum[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for (long long i = (0); i < (m); ++i) {
    cin >> from[i];
    op[from[i]].push_back(i);
    long long k;
    cin >> k;
    for (long long _ = (0); _ < (k); ++_) {
      long long first;
      cin >> first;
      if (first == -1) {
        cost[i]++;
      } else {
        in[first].push_back(i);
        to[i].push_back(first);
      }
    }
    dsum[i] = cost[i];
  }
  for (long long i = (1); i < (n + 1); ++i) {
    mn[i] = INF;
    mx[i] = -INF;
  }
  {
    set<pair<long long, long long> > q;
    for (long long i = (0); i < (m); ++i) {
      rem_op[i] = to[i].size();
    }
    for (long long i = (1); i < (n + 1); ++i) {
      out_op[i] = op[i].size();
      bool ok = 0;
      for (auto& j : op[i]) {
        if (to[j].empty()) {
          ok = 1;
          ckmin(mn[i], cost[j]);
        }
      }
      if (ok) {
        cand_end[i] = 1;
        q.insert(make_pair(mn[i], i));
      }
    }
    while (q.size()) {
      long long u = q.begin()->second;
      long long val = q.begin()->first;
      q.erase(q.begin());
      if (val != mn[u]) {
        continue;
      }
      for (auto& o : in[u]) {
        rem_op[o]--;
        dsum[o] += mn[u];
        if (rem_op[o] == 0) {
          long long v = from[o];
          if (!cand_end[v]) {
            cand_end[v] = 1;
            mn[v] = dsum[o];
            q.insert(make_pair(mn[v], v));
          } else if (ckmin(mn[v], dsum[o])) {
            q.insert(make_pair(mn[v], v));
          }
        }
      }
    }
  }
  {
    queue<long long> q;
    for (long long i = (0); i < (m); ++i) {
      rem_op[i] = to[i].size();
    }
    for (long long i = (1); i < (n + 1); ++i) {
      can_inf[i] = 1;
    }
    for (long long i = (1); i < (n + 1); ++i) {
      if (cand_end[i]) {
        out_op[i] = 0;
        for (auto& j : op[i]) {
          bool ok = 1;
          for (auto& v : to[j]) {
            ok &= cand_end[v];
          }
          if (ok && to[j].size()) {
            out_op[i]++;
          }
        }
        if (out_op[i] == 0) {
          can_inf[i] = 0;
          q.push(i);
        }
      }
    }
    while (q.size()) {
      long long u = q.front();
      q.pop();
      for (auto& o : op[u]) {
        {
          bool ok = 1;
          for (auto& v : to[o]) {
            ok &= cand_end[v];
          }
          if (ok) {
            long long newmx = cost[o];
            for (auto& v : to[o]) {
              newmx += mx[v];
            }
            ckmax(mx[u], newmx);
            ckmin(mx[u], INF);
          }
        }
      }
      for (auto& o : in[u]) {
        rem_op[o]--;
        if (rem_op[o] == 0) {
          long long v = from[o];
          if (cand_end[v]) {
            out_op[v]--;
            if (!out_op[v]) {
              can_inf[v] = 0;
              q.push(v);
            }
          }
        }
      }
    }
  }
  for (long long i = (1); i < (n + 1); ++i) {
    if (!cand_end[i]) {
      cout << -1 << ' ' << -1 << '\n';
    } else if (can_inf[i]) {
      cout << mn[i] << ' ' << -2 << '\n';
    } else {
      cout << mn[i] << ' ' << mx[i] << '\n';
    }
  }
}
