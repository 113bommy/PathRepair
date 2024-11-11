#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v);
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v);
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v);
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v);
int main() {
  long long int N;
  string s;
  cin >> N >> s;
  long long int Lcur = 0, Lreq, Rcur = 0, Rreq;
  for (long long int i = 0; i < N; i++) {
    if (s[i] == ')')
      Rcur++;
    else if (s[i] == '(')
      Lcur++;
  }
  if (Lcur > N / 2 || Rcur > N / 2 || s[0] == ')' || s[N - 1] == '(' || N % 2) {
    cout << ":(" << endl;
    return 0;
  }
  string res;
  Lreq = N / 2 - Lcur;
  Rreq = N / 2 - Rcur;
  bool check = false;
  long long int count = 0;
  for (long long int i = 0; i < N; i++) {
    if (s[i] == '?') {
      if (Lreq != 0) {
        count++;
        res.push_back('(');
        Lreq--;
      } else if (Rreq != 0) {
        count--;
        res.push_back(')');
        Rreq--;
      }
    } else {
      if (s[i] == '(')
        count++;
      else if (s[i] == ')')
        count--;
      res.push_back(s[i]);
    }
    if (count == 0 && i != N - 1) check = true;
  }
  if ((Lreq != 0 && Rreq != 0) || check)
    cout << ":(" << endl;
  else {
    cout << res << endl;
  }
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v) {
  for (auto it : v) os << it.first << " : " << it.second << "\n";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
