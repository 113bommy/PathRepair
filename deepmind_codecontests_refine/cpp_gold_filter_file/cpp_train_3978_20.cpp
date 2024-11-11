#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& out, const vector<T>& data) {
  out << "[";
  for (int i = 0; i < data.size(); ++i)
    out << data[i] << (i == data.size() - 1 ? "" : ",");
  out << "]";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const set<T>& s) {
  out << "{";
  for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
    out << *itr << " ";
  out << "}";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const multiset<T>& s) {
  out << "{";
  for (typename multiset<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
    out << *itr << " ";
  out << "}";
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
  out << "(" << p.first << "," << p.second << ")";
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, const map<T1, T2>& m) {
  for (typename map<T1, T2>::const_iterator itr = m.begin(); itr != m.end();
       ++itr)
    out << itr->first << "->" << itr->second << " ";
  return out;
}
int N;
vector<int> a;
vector<bool> used;
bool tryStart(int p1, int p2) {
  used = vector<bool>(N, false);
  vector<int> left;
  vector<int> right;
  used[p1] = used[p2] = true;
  left.push_back(a[p1]);
  left.push_back(a[p2]);
  for (int i = 0; i < p2; ++i)
    if (i != p1 && i != p2) right.push_back(a[i]);
  int d = a[p2] - a[p1];
  int nexta = a[p2] + d;
  for (int i = p2 + 1; i < N; ++i) {
    if (a[i] == nexta) {
      used[i] = true;
      left.push_back(a[i]);
      nexta += d;
    } else
      right.push_back(a[i]);
  }
  if (left.size() == N) {
    for (int i = 0; i < N - 1; ++i) printf("%d ", left[i]);
    printf("\n");
    printf("%d\n", left[N - 1]);
    exit(0);
  }
  if (right.size() <= 2) {
    for (int i = 0; i < left.size(); ++i) printf("%d ", left[i]);
    printf("\n");
    for (int i = 0; i < right.size(); ++i) printf("%d ", right[i]);
    printf("\n");
    exit(0);
  }
  int b1 = right[0];
  int b2 = right[1];
  int bd = b2 - b1;
  int nextb = b2 + bd;
  for (int i = 2; i < right.size(); ++i) {
    if (right[i] == nextb) {
      nextb += bd;
    } else {
      if (nextb == left[left.size() - 1]) {
        left.resize(left.size() - 1);
        nextb += bd;
        right.insert(right.begin() + i, nextb - bd);
      } else
        return false;
    }
  }
  for (int i = 0; i < left.size(); ++i) printf("%d ", left[i]);
  printf("\n");
  for (int i = 0; i < right.size(); ++i) printf("%d ", right[i]);
  printf("\n");
  exit(0);
}
void init() {
  cin >> N;
  a.resize(N);
  for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
  tryStart(0, 1);
  if (N >= 3) tryStart(0, 2);
  if (N >= 3) tryStart(1, 2);
  cout << "No solution" << endl;
}
void york() {}
int main() {
  init();
  york();
  return 0;
}
