#include <bits/stdc++.h>
using namespace std;
template <typename T>
void remin(T& a, const T& b) {
  if (b < a) a = b;
}
template <typename T>
void remax(T& a, const T& b) {
  if (b > a) a = b;
}
template <class T1, class T2>
inline istream& operator>>(istream& s, pair<T1, T2>& p) {
  return s >> p.first >> p.second;
}
template <class T1, class T2>
inline ostream& operator<<(ostream& s, const pair<T1, T2> p) {
  return s << "(" << p.first << " " << p.second << ")";
}
template <class T1>
inline ostream& operator<<(ostream& s, const vector<T1> container) {
  for (typename vector<T1>::const_iterator i = container.begin();
       i != container.end(); i++)
    s << *i << " ";
  return s;
}
template <class T1>
inline istream& operator>>(istream& s, vector<T1>& container) {
  for (typename vector<T1>::iterator i = container.begin();
       i != container.end(); i++)
    s >> *i;
  return s;
}
template <class T>
inline T euclide(T a, T b, T& x, T& y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <class T>
inline vector<pair<T, int> > factorize(T n) {
  vector<pair<T, int> > R;
  for (T i = 2; n > 1;) {
    if (n % i == 0) {
      int C = 0;
      for (; n % i == 0; C++, n /= i)
        ;
      R.push_back(make_pair(i, C));
    }
    i++;
    if (i > n / i) i = n;
  }
  if (n > 1) R.push_back(make_pair(n, 1));
  return R;
}
template <class T>
inline bool isPrimeNumber(T n) {
  if (n <= 1) return false;
  for (T i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
vector<int> gen_primes(int limit) {
  int sqr_lim;
  int x2, y2;
  int n;
  vector<bool> is_prime(limit + 1, false);
  sqr_lim = (int)sqrt((long double)limit);
  is_prime[2] = true;
  is_prime[3] = true;
  x2 = 0;
  for (int i = 1; i <= sqr_lim; i++) {
    x2 += 2 * i - 1;
    y2 = 0;
    for (int j = 1; j <= sqr_lim; j++) {
      y2 += 2 * j - 1;
      n = 4 * x2 + y2;
      if ((n <= limit) && (n % 12 == 1 || n % 12 == 5))
        is_prime[n] = !is_prime[n];
      n -= x2;
      if ((n <= limit) && (n % 12 == 7)) is_prime[n] = !is_prime[n];
      n -= 2 * y2;
      if ((i > j) && (n <= limit) && (n % 12 == 11)) is_prime[n] = !is_prime[n];
    }
  }
  for (int i = 5; i <= sqr_lim; i++) {
    if (is_prime[i]) {
      n = i * i;
      for (int j = n; j <= limit; j += n) {
        is_prime[j] = false;
      }
    }
  }
  int primes_count = 0;
  for (int i = 2; i < limit; i++) primes_count += is_prime[i];
  vector<int> primes;
  primes.reserve(primes_count);
  for (int i = 2; i < limit; i++)
    if (is_prime[i]) primes.push_back(i);
  return primes;
}
template <class T>
string toString(T n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
int toInt(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
long long int toInt64(string s) {
  long long int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
double toDouble(string s) {
  double r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
struct cmp {
  const vector<int>& other;
  cmp(const vector<int>& other) : other(other) {}
  bool operator()(int i, int j) { return other[i] < other[j]; }
};
int go(const vector<int>& students, int time) {
  vector<int> perm(students.size());
  for (int i(0), _n(perm.size()); i < _n; ++i) {
    perm[i] = i;
  }
  sort(perm.begin(), perm.end(), cmp(students));
  int pos(0);
  vector<int> times(students.size());
  for (vector<int>::const_iterator p = perm.begin(); p != perm.end();) {
    time += students[*p] - pos;
    pos = students[*p];
    times[*p] = time;
    int c = 0;
    for (; p != perm.end() && students[*p] == pos; ++p) {
      times[*p] = time;
      ++c;
    }
    time += 1 + c / 2;
  }
  for (int i(0), _n(times.size()); i < _n; ++i) {
    cout << times[i] << ' ';
  }
  return pos + time;
}
int main(void) {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > students(n);
  cin >> students;
  int ok_students(0);
  int time(0);
  vector<int> taxi;
  while (ok_students < n) {
    taxi.push_back(students[ok_students].second);
    time = max(time, students[ok_students].first);
    if (taxi.size() == m) {
      time = go(taxi, time);
      taxi.clear();
    }
    ++ok_students;
  }
  go(taxi, time);
  return 0;
}
