#include <bits/stdc++.h>
using namespace std;
const int N = 200031;
bool check_condition_true(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == i + 1) return false;
    if (!(v[i] & (i + 1))) return false;
  }
  return true;
}
bool check_condition_false(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == i + 1) return false;
    if (v[i] & (i + 1)) return false;
  }
  return true;
}
int n;
vector<int> order;
void show_true(vector<int> v) {
  cout << "True: " << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void show_false(vector<int> v) {
  cout << "False: " << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void show_solution_true(string st) {
  cout << "YES" << endl;
  cout << st << endl;
}
void run_solver_true() {
  if (n < 6) {
    cout << "NO" << endl;
    return;
  }
  if (n == 6) {
    show_solution_true("3 6 1 5 4 2");
    return;
  }
  if (n == 7) {
    show_solution_true("5 3 1 6 4 7 2");
    return;
  }
  if ((n & (n - 1)) == 0) {
    cout << "NO" << endl;
    return;
  }
  vector<int> ret;
  ret.push_back(5);
  ret.push_back(3);
  ret.push_back(1);
  ret.push_back(6);
  ret.push_back(4);
  ret.push_back(7);
  ret.push_back(2);
  for (int i = 8; i <= n; i *= 2) {
    int thold = min(n, i * 2 - 1);
    for (int j = i + 1; j <= thold; j++) ret.push_back(j);
    ret.push_back(i);
  }
  cout << "YES" << endl;
  for (int i = 0; i < ret.size(); i++) {
    if (i) cout << " ";
    cout << ret[i];
  }
  cout << endl;
}
bool is_bad(vector<int>& v, int lev, int ps) {
  return (v[ps] & (ps + 1) & (1 << lev));
}
void resolve(vector<int>& v, int lev, int ps) {
  swap(v[ps], v[ps - (1 << lev)]);
}
void run_solver_false() {
  if (n % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }
  for (int i = 0; i + 1 < v.size(); i += 2) {
    swap(v[i], v[i + 1]);
  }
  for (int i = 1; i <= 30; i++) {
    for (int j = 0; j < v.size(); j++) {
      if (is_bad(v, i, j)) {
        resolve(v, i, j);
      }
    }
  }
  int here = check_condition_false(v);
  if (here == 0) {
    cout << n << " SHIT" << endl;
    while (true)
      ;
  }
  cout << "YES" << endl;
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  run_solver_true();
  run_solver_false();
  cin.get();
  cin.get();
  return 0;
}
