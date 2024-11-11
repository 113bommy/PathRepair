#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
bool is_lucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
void exchange(int p, int& pos, int& jocker, int lucky, vector<int>& X,
              vector<int>& Y, vector<int>& A, map<int, set<int> >& M) {
  if (p != pos) {
    if (jocker != pos) {
      X.push_back(jocker + 1);
      Y.push_back(pos + 1);
      int tmp = jocker;
      jocker = pos;
      M[A[pos]].erase(pos);
      M[A[pos]].insert(tmp);
      int v = A[pos];
      A[pos] = lucky;
      A[tmp] = v;
    }
    X.push_back(pos + 1);
    Y.push_back(p + 1);
    jocker = p;
    int v = A[p];
    A[p] = lucky;
    A[pos] = v;
  }
  pos++;
}
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  int n;
  cin >> n;
  vector<int> A(n);
  map<int, set<int> > M;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    M[A[i]].insert(i);
  }
  bool sorted = true;
  for (int i = 1; i < n; ++i) {
    if (A[i] < A[i - 1]) {
      sorted = false;
      break;
    }
  }
  if (sorted) {
    cout << 0 << endl;
    return 0;
  }
  int lucky = -1;
  int jocker = 0;
  for (int a : A) {
    if (is_lucky(a)) {
      lucky = a;
      jocker = *M[a].begin();
      M[a].erase(M[a].begin());
      break;
    }
  }
  if (lucky == -1) {
    cout << -1 << endl;
    return 0;
  }
  int pos = 0;
  vector<int> X, Y;
  for (auto m : M) {
    int v = m.first;
    while (!M[v].empty()) {
      int p = *M[v].rbegin();
      M[v].erase(p);
      exchange(p, pos, jocker, lucky, X, Y, A, M);
    }
    if (m.first == lucky && pos < A.size() - 1) {
      int p = *M.rbegin()->second.rbegin();
      M.rbegin()->second.erase(p);
      exchange(p, pos, jocker, lucky, X, Y, A, M);
      M.rbegin()->second.insert(pos - 1);
    }
  }
  cout << X.size() << endl;
  for (int i = 0; i < X.size(); ++i) {
    cout << X[i] << " " << Y[i] << endl;
  }
  return 0;
}
