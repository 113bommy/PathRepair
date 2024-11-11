#include <bits/stdc++.h>
using namespace std;
inline long toInt(string s) {
  long v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
const double EPS = 1e-10;
const double PI = acos(-1.0);
long pw(long x, long y) {
  long ans = 1;
  for (long i = 0; i < y; i++) {
    ans = ans * x;
  }
  return ans;
}
long factorial(long x) {
  long ans = 1;
  for (int i = 1; i < x + 1; i++) {
    ans = ans * i;
  }
  return ans;
}
long combination(long x, long y) {
  return factorial(x) / factorial(y) / factorial(x - y);
}
long permutation(long x, long y) { return factorial(x) / factorial(x - y); }
template <class X>
void xdump(list<X> &l) {
  typename list<X>::iterator itr = l.begin();
  int cnt = 0;
  cerr << "dumping the list" << endl;
  while (1) {
    if (itr == l.end()) break;
    cerr << cnt << ":" << (*itr) << endl;
    itr++;
    cnt++;
  }
}
template <class X>
void xdump(vector<X> &l) {
  typename vector<X>::iterator itr = l.begin();
  int cnt = 0;
  cerr << "dumping the vector" << endl;
  while (1) {
    if (itr == l.end()) break;
    cerr << cnt << ":" << (*itr) << endl;
    itr++;
    cnt++;
  }
}
template <class X>
void xdump(queue<X> &l) {
  typename queue<X>::iterator itr = l.begin();
  int cnt = 0;
  cerr << "dumping the queue" << endl;
  while (1) {
    if (itr == l.end()) break;
    cerr << cnt << ":" << (*itr) << endl;
    itr++;
    cnt++;
  }
}
template <class X>
void xdump(stack<X> &l) {
  typename stack<X>::iterator itr = l.begin();
  int cnt = 0;
  cerr << "dumping the stack" << endl;
  while (1) {
    if (itr == l.end()) break;
    cerr << cnt << ":" << (*itr) << endl;
    itr++;
    cnt++;
  }
}
template <class X, class Y>
void xdump(vector<pair<X, Y> > v) {
  typename vector<pair<X, Y> >::iterator itr = v.begin();
  int cnt = 0;
  cerr << " dumping the vector with pair" << endl;
  while (1) {
    if (itr == v.end()) break;
    cerr << cnt << ":" << (*itr).first << " " << (*itr).second << endl;
    itr++;
    cnt++;
  }
}
template <class X, class Y>
void xdump(list<pair<X, Y> > v) {
  typename list<pair<X, Y> >::iterator itr = v.begin();
  int cnt = 0;
  cerr << " dumping the list with pair" << endl;
  while (1) {
    if (itr == v.end()) break;
    cerr << cnt << ":" << (*itr).first << " " << (*itr).second << endl;
    itr++;
    cnt++;
  }
}
template <class X, class Y>
void xdump(queue<pair<X, Y> > v) {
  typename queue<pair<X, Y> >::iterator itr = v.begin();
  int cnt = 0;
  cerr << " dumping the queue with pair" << endl;
  while (1) {
    if (itr == v.end()) break;
    cerr << cnt << ":" << (*itr).first << " " << (*itr).second << endl;
    itr++;
    cnt++;
  }
}
template <class X, class Y>
void xdump(stack<pair<X, Y> > v) {
  typename stack<pair<X, Y> >::iterator itr = v.begin();
  int cnt = 0;
  cerr << " dumping the stack with pair" << endl;
  while (1) {
    if (itr == v.end()) break;
    cerr << cnt << ":" << (*itr).first << " " << (*itr).second << endl;
    itr++;
    cnt++;
  }
}
template <class X, class Y>
void xdump(map<X, Y> m) {
  typename map<X, Y>::iterator itr = m.begin();
  int cnt = 0;
  cerr << "dumping the map" << endl;
  while (1) {
    if (itr == m.end()) break;
    cerr << cnt << ":" << (*itr).first << "/" << (*itr).second << endl;
    cnt++;
    itr++;
  }
}
int flip(int x) {
  string s;
  s = toString(x);
  string s2;
  for (int i = 0; i < s.size(); i++) {
    s2 = toString(s[i]) + s2;
  }
  return toInt(s2);
}
string flip(string s) {
  string ss;
  for (int i = 0; i < s.size(); i++) {
    ss = toString(s[i]) + ss;
  }
  return ss;
}
long mod(long a, long b) {
  if (a % b == 0) {
    return 0;
  } else {
    return a % b;
  }
}
int main() {
  long d, k, a, b, t;
  cin >> d >> k >> a >> b >> t;
  if (d <= k) {
    cout << a * d;
    return 0;
  }
  if (d % k == 0) {
    cout << min(k * a + (d - k) * b, (d / k - 1) * t + d * a);
    return 0;
  }
  cout << min(min(k * a + (d - k) * b,
                  (d / k - 1) * t + a * k * (d / k) + b * (d - k * (d / k))),
              d * a + (d / k) * t);
}
