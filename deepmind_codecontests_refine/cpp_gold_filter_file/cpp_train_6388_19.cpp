#include <bits/stdc++.h>
using namespace std;
template <typename T>
static ostream& operator<<(ostream& stream, const vector<T>& t);
template <typename T>
static istream& read(T, T, istream& = cin);
struct _print {
  string sep, end;
  bool space;
  ostream& stream;
  _print(string _sep = " ", string _end = "\n", ostream& _stream = cout)
      : sep(_sep), end(_end), space(false), stream(_stream) {}
  ~_print() { stream << end; }
  template <typename T>
  _print& operator,(const T& t) {
    if (space) stream << sep;
    space = true;
    stream << t;
    return *this;
  }
};
void __() {
  int n;
  cin >> n;
  _print(), max(0, n - 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    __();
  }
}
