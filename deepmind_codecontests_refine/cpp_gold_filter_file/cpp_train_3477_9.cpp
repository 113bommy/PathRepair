#include <bits/stdc++.h>
using namespace std;
template <class T>
T cross(complex<T> a, complex<T> b) {
  return imag(a * conj(b));
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
void setmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void setmax(T &a, T b) {
  if (b > a) a = b;
}
const int MAXR = 200;
const int NUMT = 4;
const int AA = 0;
const int AB = 1;
const int WA = 2;
const int WW = 3;
int nimVal[MAXR][NUMT];
int mex(const set<int> s) {
  for (int i = 0;; i++) {
    if (!s.count(i)) return i;
  }
}
int recurse(int r, int t) {
  if (nimVal[r][t] != -1) return nimVal[r][t];
  set<int> found;
  if (t == AA) {
    if (r == 1) return 0;
    assert(r > 1);
    for (int i = 1; r - i >= 1; i++) {
      found.insert(recurse(i, AA) ^ recurse(r - i, AA));
    }
    for (int i = 2; r - i >= 2; i++) {
      found.insert(recurse(i, AB) ^ recurse(r - i, AB));
    }
  } else if (t == AB) {
    if (r == 2) return 0;
    assert(r > 2);
    for (int i = 1; r - i >= 2; i++) {
      found.insert(recurse(i, AA) ^ recurse(r - i, AB));
    }
  } else if (t == WA) {
    if (r == 0) return 0;
    assert(r > 0);
    for (int i = 0; r - i >= 1; i++) {
      found.insert(recurse(i, WA) ^ recurse(r - i, AA));
    }
    for (int i = 0; r - i >= 2; i++) {
      found.insert(recurse(i, WA) ^ recurse(r - i, AB));
    }
  } else if (t == WW) {
    if (r < 0) return -1;
    assert(r >= 0);
    for (int i = 0; r - i >= 0; i++) {
      found.insert(recurse(i, WA) ^ recurse(r - i, WA));
    }
  }
  return nimVal[r][t] = mex(found);
}
int R, N;
pair<int, int> vals[MAXR];
bool isGood() {
  if (N == 0) return recurse(R - 1, WW);
  sort(vals, vals + N);
  int nimber =
      recurse(vals[0].first - 1, WA) ^ recurse(R - vals[N - 1].first, WA);
  for (int i = 0; i + 1 < N; i++) {
    nimber ^= recurse(vals[i + 1].first - vals[i].first,
                      (vals[i + 1].second == vals[i].second) ? AA : AB);
  }
  return nimber;
}
void io(istream &in, ostream &out) {
  memset(nimVal, -1, sizeof(nimVal));
  in >> R >> N;
  for (int i = 0; i < N; i++) {
    in >> vals[i].first >> vals[i].second;
  }
  out << (isGood() ? "WIN" : "LOSE") << '\n';
}
int main() {
  ifstream fin("335C.in");
  if (fin.good()) {
    ofstream fout("335C.out");
    io(fin, fout);
    fin.close();
    fout.close();
  } else
    io(cin, cout);
  return 0;
}
