#include <bits/stdc++.h>
using namespace std;
struct Counter {
  static int k;
  Counter() { k++; }
  ~Counter() { k--; }
};
int Counter::k = 0;
template <typename T>
void pr(const string& name, T t) {
  cout << name << " = " << t << endl;
}
template <typename T, typename... Types>
void pr(const string& names, T t, Types... rest) {
  auto comma_pos = names.find(',');
  cout << names.substr(0, comma_pos) << " = " << t << ", ";
  auto next_name_pos = names.find_first_not_of(" \t\n", comma_pos + 1);
  pr(string(names, next_name_pos), rest...);
}
void mod(long long& a, long long b) {
  a %= b;
  if (a < 0) a += b;
}
const long long MOD = 1000000007;
int A[5], N;
bool good(int a1, int a2, int a3, int a4) {
  if (4 * (a2 + a3) != 2 * (a1 + a2 + a3 + a4)) return false;
  if (2 * (a4 - a1) != a2 + a3) return false;
  return a2 >= a1 && a3 >= a2 && a4 >= a3;
}
int check(int a1, int a2, int a3, int p) {
  vector<int> a(5, 0);
  a[1] = a1;
  a[2] = a2;
  a[3] = a3;
  sort(a.begin() + 1, a.begin() + 4);
  if (p == 1) {
    if ((a[1] + a[2]) % 2) return false;
    int req = a[3] - (a[1] + a[2]) / 2;
    if (good(req, a[1], a[2], a[3]))
      return req;
    else
      return -1;
  }
  if (p == 2) {
    int req = a[1] + a[3] - a[2];
    if (good(a[1], req, a[2], a[3]))
      return req;
    else
      return -1;
  }
  if (p == 3) {
    int req = a[1] + a[3] - a[2];
    if (good(a[1], a[2], req, a[3]))
      return req;
    else
      return -1;
  }
  if (p == 4) {
    int req = a[2] + a[3] - a[1];
    if (good(a[1], a[2], a[3], req))
      return req;
    else
      return -1;
  }
  return false;
}
int main() {
  cin >> N;
  for (int i = (1); i <= (N); i++) cin >> A[i];
  if (N == 0) {
    cout << "YES\n1\n1\n3\n3";
    return 0;
  }
  if (N == 1) {
    for (int b = (1); b <= (333333); b++) {
      if (b == A[1]) {
        cout << "YES\n" << 2 * b << "\n" << 2 * b << "\n" << 3 * b;
        return 0;
      }
      if (3 * b == A[1]) {
        cout << "YES\n" << b << "\n" << 2 * b << "\n" << 1 * b;
        return 0;
      }
      if (A[1] > b && A[1] < 3 * b) {
        int other = 4 * b - A[1];
        cout << "YES\n" << b << "\n" << other << "\n" << 3 * b;
        return 0;
      }
    }
    cout << "NO";
    return 0;
  }
  if (N == 2) {
    for (int b = (1); b <= (1000000); b++)
      for (int i = (1); i <= (4); i++) {
        int v = check(A[1], A[2], b, i);
        if (v > 0) {
          cout << "YES\n" << b << "\n" << v;
          return 0;
        }
      }
    cout << "NO";
    return 0;
  }
  if (N == 4) {
    sort(A + 1, A + 5);
    if (A[2] + A[3] == A[1] + A[4] &&
        (A[4] - A[1]) * 4 == A[1] + A[2] + A[3] + A[4]) {
      cout << "YES";
      return 0;
    } else {
      cout << "NO";
      return 0;
    }
  }
  for (int i = (1); i <= (4); i++) {
    int v = check(A[1], A[2], A[3], i);
    if (v > 0) {
      cout << "YES\n" << v;
      return 0;
    }
  }
  cout << "NO";
}
