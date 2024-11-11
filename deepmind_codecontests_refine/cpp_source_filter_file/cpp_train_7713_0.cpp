#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  while (b > 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <class _T>
inline _T sqr(const _T& first) {
  return first * first;
}
struct Linked_list {
  int value;
  struct Linked_list* next;
};
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795L;
const double EPS = 1e-9;
char TEMPORARY_CHAR;
const int INF = 1e9;
inline void input(int& a) {
  a = 0;
  while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') &&
         (TEMPORARY_CHAR != '-')) {
  }
  char neg = 0;
  if (TEMPORARY_CHAR == '-') {
    neg = 1;
    TEMPORARY_CHAR = getchar();
  }
  while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {
    a = 10 * a + TEMPORARY_CHAR - '0';
    TEMPORARY_CHAR = getchar();
  }
  if (neg) a = -a;
}
inline void out(long long a) {
  if (!a) putchar('0');
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  char s[20];
  int i;
  for (i = 0; a; ++i) {
    s[i] = '0' + a % 10;
    a /= 10;
  }
  for (int j = (i)-1; j >= 0; j--) putchar(s[j]);
}
inline int nxt() {
  int(ret);
  input((ret));
  ;
  return ret;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int bin_search(vector<int> a, int b) {
  int low = 0;
  int high = (int)(a.size() - 1);
  int mid = (low + high) / 2;
  while (low <= high) {
    mid = (low + high) / 2;
    if (a[mid] > b) {
      high = mid - 1;
    } else if (a[mid] < b) {
      low = mid + 1;
    } else if (a[mid] == b) {
      return mid;
    }
  }
  return -1;
}
void mak_element(int val, struct Linked_list root) {
  struct Linked_list first;
  first.value = val;
  root.next = &first;
}
void print_list(struct Linked_list root) {
  struct Linked_list first = root;
  while (first.next != NULL) {
    cout << first.value << "-->";
    first = *first.next;
  }
}
long long get_sum(string first) {
  long long sol = 0;
  for (int i = 0; i < first.size(); i++) {
    sol += (first[i] - '0');
  }
  return sol;
}
long long sol = 1;
long long get_s(long long first) {
  if (first <= 9) {
    return sol;
  }
  sol++;
  int second = first;
  int sum = 0;
  while (second > 0) {
    sum += (second % 10);
    second /= 10;
  }
  get_s(sum);
}
int main() {
  string first;
  cin >> first;
  if (first.size() == 1) {
    cout << "1";
    return 0;
  }
  long long second = get_sum(first);
  int sol = 1;
  cout << get_s(second);
}
