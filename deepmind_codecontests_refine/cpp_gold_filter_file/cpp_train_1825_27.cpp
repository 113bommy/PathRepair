#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
int n, len1, len2;
long long int LPS[400000 + 7];
pair<long long int, char> str[400000 + 7];
pair<long long int, char> str2[400000 + 7];
void reset();
void KMP();
long long int solve();
void merging() {
  int i, j, k, p = 0;
  long long int cnt = 0;
  for (i = 0; i < len1; i++) {
    cnt = 0;
    for (j = i; j <= len1; j++) {
      if (str[i].second == str[j].second) {
        cnt += str[j].first;
      } else {
        str[p] = make_pair(cnt, str[i].second);
        p++;
        i = j - 1;
        break;
      }
    }
  }
  len1 = p;
  str[p++] = make_pair(0, '#');
  for (i = 0; i < len2; i++) {
    cnt = 0;
    for (j = i; j <= len2; j++) {
      if (str2[i].second == str2[j].second) {
        cnt += str2[j].first;
      } else {
        str[p] = make_pair(cnt, str2[i].second);
        p++;
        i = j - 1;
        break;
      }
    }
  }
  n = p;
}
int main() {
  int sz, i, j, k;
  while (scanf("%d %d", &len2, &len1) == 2) {
    for (i = 0; i < len2; i++) {
      scanf("%lld-%c ", &str2[i].first, &str2[i].second);
    }
    for (i = 0; i < len1; i++) {
      scanf("%lld-%c ", &str[i].first, &str[i].second);
    }
    merging();
    reset();
    KMP();
    printf("%lld\n", solve());
  }
  return 0;
}
void reset() {}
void KMP() {
  long long int m = 0, i, j, k;
  for (i = 1; i < n; i++) {
    if (m == 0) {
      if (str[m].second == str[i].second and str[m].first <= str[i].first) {
        LPS[i] = ++m;
      } else {
        LPS[i] = 0;
      }
    } else if (m == len1 - 1) {
      if (str[m].second == str[i].second and str[m].first <= str[i].first) {
        LPS[i] = ++m;
        while (m > 0 and str[m - 1] != str[i]) {
          m = LPS[m - 1];
        }
        if (m == 0 and str[m].first <= str[i].first) {
          m++;
        }
      } else {
        m = LPS[m - 1];
        i--;
      }
    } else {
      while (m > 0 and str[m] != str[i]) {
        m = LPS[m - 1];
      }
      if (str[m] == str[i]) {
        LPS[i] = ++m;
      } else {
        i--;
      }
    }
  }
}
long long int solve() {
  long long int rt = 0, i;
  for (i = 0; i < n; i++) {
    if (LPS[i] == len1 and len1 == 1)
      rt += ((long long int)str[i].first - (long long int)str[0].first +
             (long long int)1);
    else if (LPS[i] == len1)
      rt++;
  }
  return rt;
}
