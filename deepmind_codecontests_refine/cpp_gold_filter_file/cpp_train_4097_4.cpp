#include <bits/stdc++.h>
using namespace std;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void CI(int &_x) { scanf("%d", &_x); }
void CO(int &_x) { cout << _x; }
template <typename T>
void getarray(T a[], int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void printarray(T a[], int n) {
  for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
int dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dr4[4] = {0, 0, 1, -1};
int dc4[4] = {-1, 1, 0, 0};
int kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};
string ans = "";
string str;
int func(int inx) {
  int maxi = -1, last;
  for (int i = inx + 1; i < str.size(); i++) {
    if (str[i] > maxi) {
      maxi = str[i];
    }
  }
  for (int i = inx + 1; i < str.size(); i++) {
    if (str[i] == maxi) {
      ans += str[i];
      last = i;
    }
  }
  return last;
}
int main() {
  cin >> str;
  int st = -1;
  while (1) {
    st = func(st);
    if (st == str.size() - 1) break;
  }
  cout << ans << "\n";
}
