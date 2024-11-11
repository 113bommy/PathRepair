#include <bits/stdc++.h>
using namespace std;
const bool DEBUG = true;
const double EPS = 1e-8;
const int INF = 100000000;
const long long INFLL = 1000000000000000000LL;
int rInt() {
  int nT = -1;
  scanf("%d", &nT);
  return nT;
}
string rStr() {
  char nStr[1 << 15];
  scanf("%s", nStr);
  return nStr;
}
long long rLL() {
  long long nT = -1;
  cin >> nT;
  return nT;
}
vector<int> tokenInt(string& s) {
  stringstream sin(s);
  vector<int> v;
  int x;
  while (sin >> x) v.push_back((x));
  return v;
}
vector<string> tokenStr(string& s) {
  stringstream sin(s);
  vector<string> v;
  string x;
  while (sin >> x) v.push_back((x));
  return v;
}
vector<int> stov(string& s) {
  vector<int> v;
  for (__typeof((0)) i = (0); i < (((int)(s).size())); ++i)
    v.push_back((s[i] - '0'));
  reverse((v).begin(), (v).end());
  return v;
}
long long stol(string& s) {
  long long r = 0;
  for (__typeof((0)) i = (0); i < (((int)(s).size())); ++i)
    r = r * 10LL + (s[i] - '0');
  return r;
}
int stoi(string& s) {
  int r = 0;
  for (__typeof((0)) i = (0); i < (((int)(s).size())); ++i)
    r = r * 10 + (s[i] - '0');
  return r;
}
string ltos(long long x) {
  string s;
  do {
    s.push_back((x % 10 + '0'));
    x /= 10;
  } while (x);
  reverse((s).begin(), (s).end());
  return s;
}
vector<int> ltov(long long x) {
  vector<int> v;
  do {
    v.push_back((x % 10));
    x /= 10;
  } while (x);
  return v;
}
string itos(int x) {
  string s;
  do {
    s.push_back((x % 10 + '0'));
    x /= 10;
  } while (x);
  reverse((s).begin(), (s).end());
  return s;
}
vector<int> itov(int x) {
  vector<int> v;
  do {
    v.push_back((x % 10));
    x /= 10;
  } while (x);
  return v;
}
string vtos(vector<int>& v) {
  string s;
  int l = ((int)(v).size());
  for (__typeof((0)) i = (0); i < (l); ++i) s.push_back((v[l - i - 1] + '0'));
  return s;
}
long long vtol(vector<int>& v) {
  long long r = 0;
  int l = ((int)(v).size());
  for (__typeof((0)) i = (0); i < (l); ++i) r = r * 10LL + v[l - i - 1];
  return r;
}
int vtoi(vector<int>& v) {
  int r = 0, l = ((int)(v).size());
  for (__typeof((0)) i = (0); i < (l); ++i) r = r * 10 + v[l - i - 1];
  return r;
}
inline long long two(int x) { return (1LL << (x)); }
template <class T>
ostream& operator<<(ostream& O, vector<T>& v) {
  O << '{';
  int x = ((int)(v).size()) - 1;
  for (__typeof((0)) i = (0); i < (x); ++i) O << v[i] << ", ";
  if (x >= 0) O << v[x];
  return O << '}';
}
vector<string> split(string s, string del) {
  s += del[0];
  string temp;
  vector<string> ret;
  for (__typeof((0)) i = (0); i < (((int)(s).size())); ++i)
    if (del.find(s[i]) == string::npos)
      temp.push_back((s[i]));
    else {
      ret.push_back((temp));
      temp = "";
    }
  return ret;
}
int main() {
  int n[5];
  for (int i = 0; i < 5; ++i) cin >> n[i];
  int k = rInt();
  string s;
  for (int i = 0; i < k; ++i) {
    cin >> s;
    if (s == "S") {
      if (n[0]) {
        cout << "S" << endl;
        --n[0];
      } else if (n[1]) {
        cout << "M" << endl;
        --n[1];
      } else if (n[2]) {
        cout << "L" << endl;
        --n[2];
      } else if (n[3]) {
        cout << "XL" << endl;
        --n[3];
      } else if (n[4]) {
        cout << "XXL" << endl;
        --n[4];
      }
    } else if (s == "M") {
      if (n[1]) {
        cout << "M" << endl;
        --n[1];
      } else if (n[2]) {
        cout << "L" << endl;
        --n[2];
      } else if (n[0]) {
        cout << "S" << endl;
        --n[0];
      } else if (n[3]) {
        cout << "XL" << endl;
        --n[3];
      } else if (n[4]) {
        cout << "XXL" << endl;
        --n[4];
      }
    } else if (s == "L") {
      if (n[2]) {
        cout << "L" << endl;
        --n[2];
      } else if (n[3]) {
        cout << "XL" << endl;
        --n[3];
      } else if (n[1]) {
        cout << "M" << endl;
        --n[1];
      } else if (n[4]) {
        cout << "XXL" << endl;
        --n[4];
      } else if (n[0]) {
        cout << "S" << endl;
        --n[0];
      }
    } else if (s == "XL") {
      if (n[3]) {
        cout << "XL" << endl;
        --n[3];
      } else if (n[4]) {
        cout << "XXL" << endl;
        --n[4];
      } else if (n[2]) {
        cout << "L" << endl;
        --n[2];
      } else if (n[1]) {
        cout << "M" << endl;
        --n[1];
      } else if (n[0]) {
        cout << "S" << endl;
        --n[0];
      }
    } else if (s == "XXL") {
      if (n[4]) {
        cout << "XXL" << endl;
        --n[4];
      } else if (n[3]) {
        cout << "XL" << endl;
        --n[3];
      } else if (n[2]) {
        cout << "L" << endl;
        --n[2];
      } else if (n[1]) {
        cout << "M" << endl;
        --n[1];
      } else if (n[0]) {
        cout << "S" << endl;
        --n[0];
      }
    }
  }
  return 0;
}
