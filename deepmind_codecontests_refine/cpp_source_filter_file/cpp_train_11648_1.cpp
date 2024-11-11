#include "bits/stdc++.h"
#define int long long
#define range(i, a, b) for(int i = a; i < b; i++)
#define rep(i, a) range(i, 0, a)
#define all(a) (a).begin(),(a).end()
using namespace std;
const int MOD = 1e9 + 7, INF = 1e17;
using vi = vector <int>;
using vvi = vector <vi>;
//g++ -std==c++14


int expr(const char **);
int term(const char **);
int factor(const char **);
int number(const char **);

int expr(const char **p) {
  int val = term(p);
  while (1) {
    if (**p == '+') {
      (*p)++;
      val += term(p);
    } else if (**p == '-') {
      (*p)++;
      val -= term(p);
    } else {
      break;
    }
  }
  return val;
}

int term(const char **p) {
  int val = factor(p);
  while (1) {
    if (**p == '*') {
      (*p)++;
      val *= factor(p);
    } else if (**p == '/') {
      (*p)++;
      val /= factor(p);
    } else {
      break;
    }
  }
  return val;
}

int factor(const char **p) {
  if (**p == '(') {
    (*p)++;
    int val = expr(p);
    (*p)++;
    return val;
  }
  return number(p);
}

int number(const char **p) {
  int val = 0;
  while ('0' <= **p && **p <= '9') {
    val = val * 10 + **p - '0';
    (*p)++;
  }
  return val;
}

int main() {
  int n;
  scanf("%d", &n);
  char s[101];
  while (n--) {
    scanf("%s", s);
    const char *p = s;
    printf("%d\n", expr(&p));
  }
}