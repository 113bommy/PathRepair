#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& out, const pair<T, U>& vec) {
  out << "{ ";
  out << vec.first << ", " << vec.second;
  out << "}";
}
template <typename... T>
ostream& operator<<(ostream& out, vector<T...>& vec) {
  out << "{ ";
  for (auto& it : vec) {
    out << it << ", ";
  }
  out << "}";
}
template <typename T, typename V>
ostream& operator<<(ostream& out, map<T, V>& vec) {
  out << "{ ";
  for (auto& it : vec) {
    out << it << ", ";
  }
  out << "}";
}
int mod = 1000000007;
long long modl = 1000000007ll;
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
void read(int cur, int& vnext, int& nnext) {
  cout << "? " << cur << endl;
  fflush(stdout);
  int a, b;
  cin >> a >> b;
  if (a == -1 && b == -1) {
    exit(0);
  }
  vnext = a;
  nnext = b;
}
string sees_s =
    "rnuiokfjqovuyzejayyuvbpwakedvvtgrnsorrgfvcuml"
    "aaeasgsdmgwjxiiplypxujvxgelqdqamussgehjzheatzhpslcubqlozzorbgc"
    "kincotqrmroxmzbojwlpvsfptabjlimlhrbehrkydfnwdozdgsynmlqfxvnocwq"
    "cqlqigvvmijclcdflsqtkkfoqdvnrelyfyglzeblwnbtmyxncvwygziirpclragx"
    "xxolujqlllpkauehfajiwlvvhsdymfxbfovggyhqoseleiaasttzfnbdxkstrzckfl";
int main() {
  std::ios_base::sync_with_stdio(false);
  auto seed = hash<string>{}(sees_s);
  std::mt19937 gen(seed);
  int n;
  vector<int> a, b, c;
  a.resize(2);
  b.resize(2);
  c.resize(2);
  cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
  vector<vector<int> > p = {b, c};
  bool ok = false;
  for (int k = 0; k < 2; ++k) {
    swap(a[0], a[1]);
    int w = a[0];
    int h = a[1];
    for (int i = 0; i < 2; ++i) {
      swap(b[0], b[1]);
      for (int j = 0; j < 2; ++j) {
        swap(c[0], c[1]);
        if (b[0] <= h && b[1] <= w &&
            ((c[0] <= h && b[1] + c[1] <= w) ||
             (c[0] + b[0] <= h && c[1] <= w)))
          ok = true;
      }
    }
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
