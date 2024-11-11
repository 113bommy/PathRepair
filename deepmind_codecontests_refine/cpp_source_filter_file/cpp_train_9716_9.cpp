#include <bits/stdc++.h>
using namespace std;
const int INF_MAX = 0x7FFFFFFF;
const int INF_MIN = -(1 << 29);
const double eps = 1e-10;
const double pi = acos(-1.0);
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
int dir_4[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int dir_8[8][2] = {{0, 1},  {-1, 1}, {-1, 0}, {-1, -1},
                   {0, -1}, {1, -1}, {1, 0},  {1, 1}};
int n;
int m;
int SumMinus;
bool define;
int guiltynum;
const int MAXN = 100000;
typedef struct {
  char c;
  int x;
} POINT;
vector<POINT> VP(MAXN);
vector<int> pluss(MAXN), minuss(MAXN);
vector<bool> guilty(MAXN);
void initial() {
  SumMinus = 0;
  define = false;
  guiltynum = 0;
  return;
}
void input() {
  for (int i = 0; i < n; i++) {
    char c;
    int temp;
    POINT kk;
    scanf("\n%c%d", &c, &temp);
    temp--;
    kk.c = c;
    kk.x = temp;
    VP[i] = kk;
    if (c == '+') {
      pluss[temp]++;
    } else {
      minuss[temp]++;
      SumMinus++;
    }
  }
  return;
}
void cal() {
  for (int i = 0; i < n; i++) {
    if (pluss[i] + SumMinus - minuss[i] == m) {
      guilty[i] = true;
      guiltynum++;
    }
  }
  return;
}
void output() {
  for (int i = 0; i < n; i++) {
    if (guiltynum == 1) {
      if (guilty[VP[i].x] && VP[i].c == '+') {
        cout << "True" << endl;
      }
      if (guilty[VP[i].x] && VP[i].c == '-') {
        cout << "Lie" << endl;
      }
      if (!guilty[VP[i].x] && VP[i].c == '+') {
        cout << "Lie" << endl;
      }
      if (!guilty[VP[i].x] && VP[i].c == '-') {
        cout << "True" << endl;
      }
    } else {
      if (guilty[VP[i].x]) {
        cout << "Not defined" << endl;
      }
      if (!guilty[VP[i].x] && VP[i].c == '-') {
        cout << "Truth" << endl;
      }
      if (!guilty[VP[i].x] && VP[i].c == '+') {
        cout << "Lie" << endl;
      }
    }
  }
  return;
}
void debug() {
  cout << "n=" << n << endl;
  cout << "m=" << m << endl;
  cout << "SumMinus=" << SumMinus << endl;
  cout << "guiltynum=" << guiltynum << endl;
  cout << "pluss=" << endl;
  for (int i = 0; i < n; i++) {
    cout << pluss[i] << " ";
  }
  cout << endl;
  cout << "minus=" << endl;
  for (int i = 0; i < n; i++) {
    cout << minuss[i] << " ";
  }
  cout << endl;
  cout << "guilty" << endl;
  for (int i = 0; i < n; i++) {
    cout << guilty[i] << " ";
  }
  cout << endl;
}
int main() {
  while (cin >> n >> m) {
    initial();
    input();
    cal();
    output();
  }
  return 0;
}
