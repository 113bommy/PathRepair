#include <bits/stdc++.h>
using namespace std;
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
template <class T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
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
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int xx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int yy[] = {2, 2, 1, -1, -2, -2, -1, 1};
bool on[100000 + 10 + 10], prime[100000 + 10 + 10];
vector<int> vec;
set<int> ss[100000 + 10 + 10];
int cnt[100000 + 10 + 10];
void seive() {
  for (int i = 2; i <= sqrt(100000 + 10); i++) {
    if (!prime[i])
      for (long long j = i * i; j <= 100000 + 10; j += i) prime[j] = true;
  }
  for (int i = 2; i <= sqrt(100000 + 10); i++)
    if (!prime[i]) vec.push_back(i);
}
void process_on(int k) {
  int a = k, j, p;
  int flag = -1;
  for (j = 0; j < vec.size(); j++) {
    p = vec[j];
    if (k % p == 0) {
      if (cnt[p]) {
        flag = p;
        break;
      }
      while (k % p == 0) k /= p;
    }
  }
  if (k > 1 && cnt[k]) flag = k;
  if (flag == -1) {
    printf("Success\n");
    k = a;
    on[k] = true;
    for (j = 0; j < vec.size(); j++) {
      p = vec[j];
      if (k % p == 0) {
        ss[p].insert(a);
        cnt[p]++;
        while (k % p == 0) k /= p;
      }
    }
    if (k > 1) {
      ss[k].insert(a);
      cnt[k]++;
    }
  } else {
    set<int>::iterator it;
    for (it = ss[flag].begin(); it != ss[flag].end(); it++) {
      printf("Conflict with %d\n", *it);
      break;
    }
  }
}
void process_off(int k) {
  int a = k, j, p;
  printf("Success\n");
  on[k] = false;
  for (j = 0; j < vec.size(); j++) {
    p = vec[j];
    if (k % p == 0) {
      cnt[p]--;
      ss[p].erase(a);
      while (k % p == 0) k /= p;
    }
  }
  if (k > 1) {
    ss[k].erase(a);
    cnt[k]--;
  }
}
int main() {
  seive();
  int n, m, i, j, k, p;
  char ch;
  scanf("%d %d", &n, &m);
  memset(on, false, sizeof on);
  memset(cnt, 0, sizeof cnt);
  while (m--) {
    scanf(" %c %d", &ch, &k);
    if (ch == '+') {
      if (on[k])
        printf("Already on\n");
      else
        process_on(k);
    } else {
      if (!on[k])
        printf("Already off\n");
      else
        process_off(k);
    }
  }
  return 0;
}
