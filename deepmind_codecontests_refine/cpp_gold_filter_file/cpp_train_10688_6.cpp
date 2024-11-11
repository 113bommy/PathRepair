#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int x[100005];
long long int y[100005];
long long int sign[100005];
void print_ans() {
  for (long long int i = 1; i <= n; i++) {
    cout << sign[i] << " ";
  }
  cout << "\n";
  exit(0);
}
long long int len(long long int x1, long long int y1, long long int x2,
                  long long int y2) {
  return ((x1 + x2) * (x1 + x2)) + ((y1 + y2) * (y1 + y2));
}
int main() {
  cin >> n;
  for (long long int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  if (n == 1) {
    sign[1] = 1;
    print_ans();
  }
  set<pair<long long int, long long int>> s1;
  set<pair<long long int, long long int>> s2;
  s1.insert({1, 1});
  s2.insert({2, 1});
  long long int x1 = x[1];
  long long int x2 = x[2];
  long long int y1 = y[1];
  long long int y2 = y[2];
  long long int mx_len = 1e12;
  long long int sign1 = 1;
  long long int sign2 = 1;
  for (long long int i = 3; i <= n; i++) {
    if (len(x1, y1, x2, y2) <= mx_len) {
      if (s2.size() > s1.size()) {
        swap(s1, s2);
        swap(sign1, sign2);
      }
      for (auto it : s2) {
        if (sign1 == -1) {
          s1.insert({it.first, -it.second * sign2});
        } else {
          s1.insert({it.first, it.second * sign2});
        }
      }
      s2.clear();
      s2.insert({i, 1});
      x1 += x2;
      y1 += y2;
      x2 = x[i];
      y2 = y[i];
      sign2 = 1;
    } else if (len(x1, y1, -x2, -y2) <= mx_len) {
      if (s2.size() > s1.size()) {
        swap(s1, s2);
        swap(sign1, sign2);
        sign1 *= -1;
      } else {
        sign2 *= -1;
      }
      for (auto it : s2) {
        if (sign1 == -1) {
          s1.insert({it.first, -it.second * sign2});
        } else {
          s1.insert({it.first, it.second * sign2});
        }
      }
      s2.clear();
      s2.insert({i, 1});
      x1 -= x2;
      y1 -= y2;
      x2 = x[i];
      y2 = y[i];
      sign2 = 1;
    } else if (len(x1, y1, x[i], y[i]) <= mx_len) {
      if (sign1 == -1) {
        s1.insert({i, -1});
      } else {
        s1.insert({i, 1});
      }
      x1 += x[i];
      y1 += y[i];
    } else if (len(x1, y1, -x[i], -y[i]) <= mx_len) {
      if (sign1 == -1) {
        s1.insert({i, 1});
      } else {
        s1.insert({i, -1});
      }
      x1 -= x[i];
      y1 -= y[i];
    } else if (len(x2, y2, x[i], y[i]) <= mx_len) {
      if (sign2 == -1) {
        s2.insert({i, -1});
      } else {
        s2.insert({i, 1});
      }
      x2 += x[i];
      y2 += y[i];
    } else if (len(x2, y2, -x[i], -y[i]) <= mx_len) {
      if (sign2 == -1) {
        s2.insert({i, 1});
      } else {
        s2.insert({i, -1});
      }
      x2 -= x[i];
      y2 -= y[i];
    }
  }
  if (len(x1, y1, x2, y2) > len(x1, y1, -x2, -y2)) {
    sign2 *= -1;
    x1 -= x2;
    y1 -= y2;
  } else {
    x1 += x2;
    y1 += y2;
  }
  for (auto it : s1) {
    sign[it.first] = it.second * sign1;
  }
  for (auto it : s2) {
    sign[it.first] = it.second * sign2;
  }
  print_ans();
}
