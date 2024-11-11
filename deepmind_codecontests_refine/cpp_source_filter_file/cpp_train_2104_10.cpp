#include <bits/stdc++.h>
using namespace std;
class segment_tree {
  vector<long long> tmax, tmin;
  long size;

 public:
  segment_tree(long n) {
    tmax.assign(4 * n + 1, -200000000);
    tmin.assign(4 * n + 1, 200000000);
    size = n;
  }
  void initialize_array(vector<long long>& v) {
    initialize_with_array(1, 0, size - 1, v);
  }
  void initialize_with_array(long startpos, long l, long r,
                             vector<long long>& v) {
    if (l == r) {
      tmax[startpos] = v[l];
      tmin[startpos] = v[l];
    } else {
      long m = (l + r) / 2;
      initialize_with_array(2 * startpos, l, m, v);
      initialize_with_array(2 * startpos + 1, m + 1, r, v);
      tmax[startpos] = max(tmax[startpos * 2], tmax[startpos * 2 + 1]);
      tmin[startpos] = min(tmin[startpos * 2], tmin[startpos * 2 + 1]);
    }
  }
  void update(long index, long long val) {
    update_full(1, 0, size - 1, index, val);
  }
  void update_full(long startpos, long l, long r, long index, long long val) {
    if (l == r) {
      tmax[startpos] = val;
      tmin[startpos] = val;
    } else {
      long m = (l + r) / 2;
      if (index <= m)
        update_full(2 * startpos, l, m, index, val);
      else
        update_full(2 * startpos + 1, m + 1, r, index, val);
      tmax[startpos] = max(tmax[startpos * 2], tmax[startpos * 2 + 1]);
      tmin[startpos] = min(tmin[startpos * 2], tmin[startpos * 2 + 1]);
    }
  }
  long long query_min(long l, long r) {
    if (l > r) {
      return 200000000;
    }
    return query_full_min(1, 0, size - 1, l, r);
  }
  long long query_full_min(long startpos, long left, long right, long l,
                           long r) {
    if ((left >= l) && (right <= r)) return tmin[startpos];
    long m = (left + right) / 2;
    long long ans;
    ans = 200000000;
    if (m >= l) {
      ans = min(ans, query_full_min(startpos * 2, left, m, l, r));
    }
    if (m + 1 <= r) {
      ans = min(ans, query_full_min(startpos * 2 + 1, m + 1, right, l, r));
    }
    return ans;
  }
  long long query_max(long l, long r) {
    if (l > r) {
      return 0;
    }
    return query_full_max(1, 0, size - 1, l, r);
  }
  long long query_full_max(long startpos, long left, long right, long l,
                           long r) {
    if ((left >= l) && (right <= r)) return tmax[startpos];
    long m = (left + right) / 2;
    long long ans;
    ans = -(1LL << 60);
    if (m >= l) {
      ans = max(ans, query_full_max(startpos * 2, left, m, l, r));
    }
    if (m + 1 <= r) {
      ans = max(ans, query_full_max(startpos * 2 + 1, m + 1, right, l, r));
    }
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i, j, k, pos, ans, minn, maxx, ct = 0, a, b;
  string s;
  cin >> n >> s;
  n = s.length();
  stack<char> st[2];
  vector<char> v(1000010, ' ');
  vector<int> p = {1, 0}, vleft(1000010, 0), vright(1000010, 0);
  segment_tree stleft(1000010), stright(1000010);
  pos = 0;
  for (auto ch : s) {
    char chh = ch;
    if (ch == 'L') {
      if ((pos != 0) && (p[0] > 1)) {
        p[0]--;
        p[1]++;
        ch = v[pos];
        if (ch == '(') {
          vright[p[1]] = vright[p[1] - 1] - 1;
        } else if (ch == ')') {
          vright[p[1]] = vright[p[1] - 1] + 1;
        } else
          vright[p[1]] = vright[p[1] - 1];
        stright.update(p[1], vright[p[1]]);
        pos--;
      }
    } else if (ch == 'R') {
      pos++;
      if (p[1] > 0) p[1]--;
      p[0]++;
      ch = v[pos];
      if (ch == '(') {
        vleft[p[0]] = vleft[p[0] - 1] + 1;
      } else if (ch == ')') {
        vleft[p[0]] = vleft[p[0] - 1] - 1;
      } else
        vleft[p[0]] = vleft[p[0] - 1];
      stleft.update(p[0], vleft[p[0]]);
    } else {
      v[pos] = ch;
      if (ch == '(') {
        vleft[p[0]] = vleft[p[0] - 1] + 1;
      } else if (ch == ')') {
        vleft[p[0]] = vleft[p[0] - 1] - 1;
      } else
        vleft[p[0]] = vleft[p[0] - 1];
      stleft.update(p[0], vleft[p[0]]);
    }
    if (vleft[p[0]] != vright[p[1]])
      ans = -1;
    else {
      a = stleft.query_min(0, p[0]), b = stright.query_min(0, p[1]);
      if ((a < 0) || (b < 0))
        ans = -1;
      else
        ans = max(stleft.query_max(0, p[0]), stright.query_max(0, p[1]));
    }
    cout << ans << " ";
    ct++;
    if (ct == 83) {
      i = 0;
    }
  }
  cout << "\n";
  return 0;
}
