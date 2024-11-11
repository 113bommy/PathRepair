#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
long long gcdx(long long a, long long b) { return b ? gcdx(b, a % b) : a; }
long long GCD(long long a, long long b) { return gcdx(abs(a), abs(b)); }
void SetBit(int &m, int ind, int val) {
  if (val)
    m = (m | (1 << ind));
  else
    m = (m & ~(1 << ind));
}
bool GetBit(int m, int ind) {
  int a = (1 << ind);
  a = (a & m);
  return a;
}
int CntBits(int m) {
  int ret = 0;
  while (m) {
    ret += (m % 2);
    m /= 2;
  }
  return ret;
}
bool IsSmlLtr(char c) {
  if (c >= 'a' && c <= 'z') return 1;
  return 0;
}
bool IsCapLtr(char c) {
  if (c >= 'A' && c <= 'Z') return 1;
  return 0;
}
constexpr auto pi = 3.141592653589793;
const long long mod = 1000000007;
long long pow_mod(long long a, long long b, long long modulo = mod) {
  if (b == 0) return 1ll;
  if (b % 2ll) return (a * pow_mod((a * a) % modulo, b / 2ll)) % modulo;
  return pow_mod((a * a) % modulo, b / 2ll);
}
const long long mod2 = 998244353;
const long long mod3 = 1000000009;
bool print_;
constexpr auto infl = LLONG_MAX;
constexpr auto inf = INT_MAX;
constexpr auto eps = 0.000000000001;
constexpr auto M = 200100;
constexpr auto N = 110;
long long n, m, tmp, Q, t, ans, cnt, sum, mini, maxi, r, p, k;
string a[N];
vector<int> opX;
vector<int> opY;
void printArr() {
  cout << "#####################\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  cout << "#####################\n";
}
void clearData() {
  opX.clear();
  opY.clear();
}
void addOp(int x, int y) {
  opX.push_back(x + 1);
  opY.push_back(y + 1);
}
void swapVal(int x, int y) {
  if (a[x][y] == '1')
    a[x][y] = '0';
  else
    a[x][y] = '1';
  addOp(x, y);
}
void clearSpecialSquareX(int y, int cnt) {
  int thisX = n - 2, thisY = y;
  if (cnt == 3) {
    if (a[thisX][thisY] == '1') swapVal(thisX, thisY);
    if (a[thisX][thisY + 1] == '1') swapVal(thisX, thisY + 1);
    if (a[thisX + 1][thisY] == '1') swapVal(thisX + 1, thisY);
    if (a[thisX + 1][thisY + 1] == '1') swapVal(thisX + 1, thisY + 1);
  } else if (cnt == 2) {
    bool swap1 = true;
    if (a[thisX][thisY] == '0')
      swapVal(thisX, thisY);
    else if (swap1) {
      swap1 = false;
      swapVal(thisX, thisY);
    }
    if (a[thisX][thisY + 1] == '0')
      swapVal(thisX, thisY + 1);
    else if (swap1) {
      swap1 = false;
      swapVal(thisX, thisY + 1);
    }
    if (a[thisX + 1][thisY] == '0')
      swapVal(thisX + 1, thisY);
    else if (swap1) {
      swap1 = false;
      swapVal(thisX + 1, thisY);
    }
    if (a[thisX + 1][thisY + 1] == '0')
      swapVal(thisX + 1, thisY + 1);
    else if (swap1) {
      swap1 = false;
      swapVal(thisX + 1, thisY + 1);
    }
    clearSpecialSquareX(y, 3);
  } else if (cnt == 1) {
    int swap0 = 2;
    if (a[thisX][thisY] == '1')
      swapVal(thisX, thisY);
    else if (swap0 > 0) {
      swap0--;
      swapVal(thisX, thisY);
    }
    if (a[thisX][thisY + 1] == '1')
      swapVal(thisX, thisY + 1);
    else if (swap0 > 0) {
      swap0--;
      swapVal(thisX, thisY + 1);
    }
    if (a[thisX + 1][thisY] == '1')
      swapVal(thisX + 1, thisY);
    else if (swap0 > 0) {
      swap0--;
      swapVal(thisX + 1, thisY);
    }
    if (a[thisX + 1][thisY + 1] == '1')
      swapVal(thisX + 1, thisY + 1);
    else if (swap0 > 0) {
      swap0--;
      swapVal(thisX + 1, thisY + 1);
    }
    clearSpecialSquareX(y, 2);
  } else if (cnt == 4) {
    swapVal(thisX, thisY);
    swapVal(thisX, thisY + 1);
    swapVal(thisX + 1, thisY);
    clearSpecialSquareX(y, 3);
  }
}
void clearSpecialSquare(int y) {
  int thisX = n - 2, thisY = y, cnt_1 = 0;
  if (a[thisX][thisY] == '1') cnt_1++;
  if (a[thisX][thisY + 1] == '1') cnt_1++;
  if (a[thisX + 1][thisY] == '1') cnt_1++;
  if (a[thisX + 1][thisY + 1] == '1') cnt_1++;
  if (cnt_1 > 0) clearSpecialSquareX(y, cnt_1);
}
void clearRow(int x, int y) {
  if (y >= m - 1) return;
  if (y % 2 && y != m - 2) return;
  if (x >= n - 2) return;
  if (a[x][y] == '1' || a[x][y + 1] == '1') {
    int temp = 3;
    if (a[x][y] == '1') {
      swapVal(x, y);
      temp--;
    }
    if (a[x][y + 1] == '1') {
      swapVal(x, y + 1);
      temp--;
    }
    swapVal(x + 1, y);
    temp--;
    if (temp > 0) swapVal(x + 1, y + 1);
  }
}
void clearLastRow() {
  for (int i = 0; i <= m - 3; i++) {
    int thisX = n - 2, thisY = i;
    if (a[thisX][thisY] == '1' || a[thisX + 1][thisY] == '1') {
      int swaps = 3;
      if (a[thisX][thisY] == '1') {
        swapVal(thisX, thisY);
        swaps--;
      }
      if (a[thisX + 1][thisY] == '1') {
        swapVal(thisX + 1, thisY);
        swaps--;
      }
      swapVal(thisX, thisY + 1);
      swaps--;
      if (swaps > 0) swapVal(thisX + 1, thisY + 1);
    }
  }
  clearSpecialSquare(m - 2);
}
void clearRows() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      clearRow(i, j);
    }
  clearLastRow();
}
void printAns() {
  int ansCnt = opX.size();
  cout << ansCnt / 3 << endl;
  int currCnt = 0;
  for (int i = 0; i < ansCnt; i++) {
    cout << opX[i] << " " << opY[i];
    currCnt++;
    if (currCnt == 3) {
      currCnt = 0;
      cout << endl;
    } else
      cout << " ";
  }
}
void printLN() { cout << "..............START..................\n"; }
void printEndl() { cout << ".....................................\n\n\n"; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  print_ = false;
  cin >> t;
  while (t--) {
    clearData();
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    clearRows();
    printAns();
  }
  return 0;
}
