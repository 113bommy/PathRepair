#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
void pr(const pair<T1, T2>& x);
template <class T, size_t SZ>
void pr(const array<T, SZ>& x);
template <class T>
void pr(const vector<T>& x);
template <class T>
void pr(const set<T>& x);
template <class T1, class T2>
void pr(const map<T1, T2>& x);
template <class T>
void pr(const T& x) {
  cout << x;
}
template <class Arg, class... Args>
void pr(const Arg& first, const Args&... rest) {
  pr(first);
  pr(rest...);
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x) {
  pr("{", x.first, ", ", x.second, "}");
}
template <class T>
void prContain(const T& x) {
  pr("{");
  bool fst = 1;
  for (auto& a : x) pr(!fst ? ", " : "", a), fst = 0;
  pr("}");
}
template <class T, size_t SZ>
void pr(const array<T, SZ>& x) {
  prContain(x);
}
template <class T>
void pr(const vector<T>& x) {
  prContain(x);
}
template <class T>
void pr(const set<T>& x) {
  prContain(x);
}
template <class T1, class T2>
void pr(const map<T1, T2>& x) {
  prContain(x);
}
void ps() { pr("\n"); }
template <class Arg, class... Args>
void ps(const Arg& first, const Args&... rest) {
  pr(first, " ");
  ps(rest...);
}
template <typename T>
int remin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
int remax(T& a, const T& b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
int N, a[200005];
int main(int argc, const char** argv) {
  scanf("%d\n", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> ans;
  string directions;
  int li = 0, ri = N - 1;
  ans.push_back(-1E9);
  for (int i = 0; i < N; ++i) {
    if (li > ri) {
      break;
    }
    if (ans.back() < a[li] && ans.back() < a[ri]) {
      if (a[li] == a[ri]) {
        int l = 0, r = 0;
        string dir1 = "", dir2 = "";
        while (a[li + l] > a[li + l - 1]) {
          dir1 += "L";
          l++;
        }
        while (a[ri - r] > a[ri - r + 1]) {
          dir2 += "R";
          r++;
        }
        if (l > r) {
          directions += dir1;
        } else {
          directions += dir2;
        }
        goto end;
      } else if (a[li] < a[ri]) {
        directions += "L";
        ans.push_back(a[li]);
        li++;
      } else {
        ans.push_back(a[ri]);
        directions += "R";
        ri--;
      }
    } else if (ans.back() < a[li]) {
      directions += 'L';
      ans.push_back(a[li]);
      li++;
    } else if (ans.back() < a[ri]) {
      directions += 'R';
      ans.push_back(a[ri]);
      --ri;
    }
  }
end:
  printf("%d\n%s\n", (int)directions.size(), directions.c_str());
  return 0;
}
