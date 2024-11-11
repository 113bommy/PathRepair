#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void checkMax(T &a, const T &b) {
  if (a < b) a = b;
}
template <class T>
inline void checkMin(T &a, const T &b) {
  if (b < a) a = b;
}
template <class T>
inline std::string toString(const T &n) {
  std::ostringstream out;
  out << n;
  out.flush();
  return out.str();
}
template <class T>
inline T toValue(const std::string &s) {
  T x;
  std::istringstream in(s);
  in >> x;
  return x;
}
bool hasNext() {
  char c;
  if (scanf(" %c", &c) == EOF) return false;
  ungetc(c, stdin);
  return true;
}
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
std::string dir[] = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};
int tenPower[10] = {0x1,     0xA,     0x64,     0x3E8,     0x2710,
                    0x186A0, 0xF4240, 0x989680, 0x5F5E100, 0x3B9ACA00};
const int N = 1000000 + 128;
int aL, a[N], posA[N];
int bL, b[N], posB[N];
void read() {
  memset(posA, -1, sizeof(posA));
  memset(posB, -1, sizeof(posB));
  cin >> aL >> bL;
  for (int i = 0; i < (int)(aL); ++i) {
    scanf("%d", &a[i]);
    posA[a[i]] = i;
  }
  for (int i = 0; i < (int)(bL); ++i) {
    scanf("%d", &b[i]);
    posB[b[i]] = i;
  }
}
bool ok(int l, int r, int r1) {
  if (-1 == r1) {
    return false;
  }
  if (r >= l) {
    return r1 > r || r1 < l;
  } else {
    return r1 > r && r1 < l;
  }
}
int getLength(int l, int r) {
  if (r >= l) {
    return r - l + 1;
  } else {
    return r - l + 1 + aL;
  }
}
int solve() {
  int maxL = 0;
  for (int l = 0, r = -1; l < aL; ++l) {
    if (-1 == posB[a[l]]) {
      continue;
    }
    if (r == -1) {
      r = l;
    }
    while ((r + 1) % aL != l &&
           ok(posB[a[l]], posB[a[r]], posB[a[(r + 1) % aL]])) {
      r = (r + 1) % aL;
    }
    checkMax(maxL, getLength(l, r));
    if (r == l) {
      r = -1;
    }
  }
  return maxL;
}
void run(const int caseID) {
  read();
  cout << solve() << endl;
}
void runWithCaseT() {
  int caseT;
  scanf("%d", &caseT);
  for (int caseID = 1; caseID <= caseT; ++caseID) {
    run(caseID);
  }
}
void runWithoutCaseT() {
  int caseID = 0;
  while (hasNext()) {
    run(++caseID);
  }
}
int main(int argc, char *argv[]) {
  ;
  runWithoutCaseT();
  return (EXIT_SUCCESS);
}
