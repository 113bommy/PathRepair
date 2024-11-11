#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

long long gcd(long long a, long long b) {
  if (a <= 0) { return b; }
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

struct Rational {
  long long p, q;
  Rational(long long p = 0, long long q = 1) : p(p), q(q) {
    assert(q != 0);
    normalize();
  }
  void normalize() {
    if (q < 0) { p *= -1; q *= -1; }
    long long d = gcd(p > 0 ? p : -p, q);
    if (d == 0) {
      p = 0;
      q = 1;
    } else {
      p /= d;
      q /= d;
    }
    assert(q != 0);
  }
  Rational &operator-() {
    p *= -1;
    return *this;
  }
  Rational operator-() const {
    return Rational(-p, q);
  }
  Rational operator+(const Rational &rhs) const {
    return Rational(p * rhs.q + rhs.p * q, q * rhs.q);
  }
  Rational operator-(const Rational &rhs) const {
    return Rational(p * rhs.q - rhs.p * q, q * rhs.q);
  }
  Rational operator*(const Rational &rhs) const {
    return Rational(p * rhs.p, q * rhs.q);
  }
  Rational operator/(const Rational &rhs) const {
    assert(rhs.p != 0);
    return Rational(p * rhs.q, q * rhs.p);
  }
  Rational &operator+=(const Rational &rhs) { *this = *this + rhs; return *this; }
  Rational &operator-=(const Rational &rhs) { *this = *this - rhs; return *this; }
  Rational &operator*=(const Rational &rhs) { *this = *this * rhs; return *this; }
  Rational &operator/=(const Rational &rhs) { *this = *this / rhs; return *this; }
  bool operator<(const Rational &rhs) const {
    return p * rhs.q < rhs.p * q;
  }
  bool operator>(const Rational &rhs) const {
    return rhs < *this;
  }
  bool operator<=(const Rational &rhs) const {
    return !(*this > rhs);
  }
  bool operator>=(const Rational &rhs) const {
    return !(*this < rhs);
  }
  bool operator!=(const Rational &rhs) const {
    return (*this < rhs || *this > rhs);
  }
  bool operator==(const Rational &rhs) const {
    return !(*this != rhs);
  }

  Rational abs() { return Rational(p > 0 ? p : -p, q); }
};
ostream &operator<<(ostream &os, const Rational &rhs) {
  //os << '(' << rhs.p << "/" << rhs.q << ')';
  os << (double)rhs.p / rhs.q;
  return os;
}

typedef vector<Rational> Array;
typedef vector<Array> Matrix;

void printMatrix(const Matrix &matrix) {
  REP(y, matrix.size()) {
    REP(x, matrix.size()) {
      cout << matrix[y][x] << " ";
    }
    cout << endl;
  }
}

Array GaussElimination(Matrix matrix, Array vect, int m) {
  const int n = vect.size();
  Array ret(n, Rational(0, 1));
  for (int x = 0; x < n; x++) {
    int pivot = x;
    for (int i = x + 1; i < n; i++) {
      if (matrix[i][x].abs() > matrix[pivot][x].abs()) { pivot = i; }
    }
    swap(matrix[x], matrix[pivot]);
    if (matrix[x][x] == Rational(0, 1)) { continue; }
    for (int y = x + 1; y < n; y++) {
      Rational ratio = -matrix[y][x] / matrix[x][x];
      matrix[y][x] = Rational(0, 1);
      for (int i = x + 1; i < n; i++) {
        matrix[y][i] += matrix[x][i] * ratio;
      }
    }
  }
  ret[m - 1] = Rational(1, 1);
  for (int x = m - 2; x >= 0; x--) {
    Rational sum = vect[x];
    for (int i = n - 1; i > x; i--) {
      sum -= ret[i] * matrix[x][i];
    }
    assert(matrix[x][x] != 0);
    ret[x] = sum / matrix[x][x];
  }
  return ret;
}

struct Mol {
  map<int, int> atoms;
  Mol &operator+=(const Mol &rhs) {
    FORIT(it, rhs.atoms) {
      if (!atoms.count(it->first)) { atoms[it->first] = 0; }
      atoms[it->first] += it->second;
    }
    return *this;
  }
  Mol &operator*=(const ll &rhs) {
    FORIT(it, atoms) { it->second *= rhs; }
    return *this;
  }
};
int molecule(int index, Mol &mol);

map<string, int> atom;
string revatom[1000];
vector<Mol> mols;
char str[100000];
int effect;

void printMols() {
  REP(i, mols.size()) {
    Mol mol = mols[i];
    FORIT(it, mol.atoms) {
      cout << revatom[it->first] << it->second << " ";
    }
    cout << endl;
  }
}

int chemical_element(int index, Mol &mol) {
  string s;
  char c = str[index++];
  s += c;
  assert(isupper(c));
  if (islower(str[index])) {
    c = str[index++];
    s += c;
  }
  if (!atom.count(s)) {
    revatom[atom.size()] = s;
    atom.insert(make_pair(s, atom.size()));
  }
  int id = atom[s];
  mol.atoms[id] = effect;
  return index;
}

int unit_group(int index, Mol &mol) {
  char c = str[index];
  if (c == '(') {
    index++;
    index = molecule(index, mol);
    c = str[index++];
    assert(c == ')');
  } else {
    index = chemical_element(index, mol);
  }
  return index;
}

int group(int index, Mol &mol) {
  index = unit_group(index, mol);
  char c = str[index];
  if (isdigit(c)) {
    int num = atoi(str + index);
    assert(num > 0);
    mol *= num;
    while (isdigit(str[index])) { index++; }
  }
  return index;
}

int molecule(int index, Mol &mol) {
  Mol child;
  index = group(index, child);
  mol += child;
  char c = str[index];
  if (c != '-' && c != '+' && c != '.' && c != ')') {
    index = molecule(index, mol);
  }
  return index;
}

int molecule_sequence(int index) {
  Mol mol;
  index = molecule(index, mol);
  mols.push_back(mol);
  char c = str[index];
  if (c == '+') {
    index++;
    index = molecule_sequence(index);
  }
  return index;
}

int chemical_equation(int index) {
  effect = 1;
  index = molecule_sequence(index);
  char c = str[index++];
  assert(c == '-');
  c = str[index++];
  assert(c == '>');
  effect = -1;
  index = molecule_sequence(index);
  assert(str[index] == '.');
  return index;
}

int main() {
  while (fgets(str, 9999, stdin), str[0] != '.') {
    atom.clear();
    mols.clear();
    chemical_equation(0);
    int h = atom.size();
    int w = mols.size();
    int n = max(h, w);
    Matrix matrix(n, Array(n, 0));
    Array vect(n, 0);
    REP(x, mols.size()) {
      FORIT(it, mols[x].atoms) {
        int y = it->first;
        matrix[y][x] = Rational(it->second, 1);
      }
    }
    //printMatrix(matrix);
    //cout << endl;
    Array ans = GaussElimination(matrix, vect, mols.size());
    ll l = 1;
    REP(i, mols.size()) {
      l = lcm(l, ans[i].q);
    }
    ll g = ans[0].p * l / ans[0].q;
    REP(i, mols.size()) {
      ans[i] *= l;
      g = gcd(g, ans[i].p);
    }
    REP(i, mols.size()) {
      ans[i] /= g;
    }
    REP(i, mols.size()) {
      if (i != 0) { putchar(' '); }
      printf("%lld", ans[i].p);
    }
    puts("");
  }
}