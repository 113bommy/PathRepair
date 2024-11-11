#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000")
using namespace std;
template <class T>
T inline sqr(T x) {
  return x * x;
}
const double pi = 3.1415926535897932384626433832795;
const double eps = 1e-8;
const int maxn = 100500, maxq = 1050;
bool isGood[maxn];
bool good(int x) {
  while (x) {
    int c = x % 10;
    if (c != 4 && c != 7) return false;
    x /= 10;
  }
  return true;
}
long long C2(long long n) { return (n * (n + 1)) / 2; }
vector<int> listOcc[maxq];
long long count00(vector<int> a) {
  long long res = 0;
  for (int i = 1; i < a.size() - 1; i++)
    for (int j = i + 1; j < a.size(); j++) {
      long long q1 = C2(a[i] - a[i - 1] - 1);
      long long q2 = C2(a[j] - a[j - 1] - 1);
      res += q1 * q2;
    }
  for (int i = 1; i < a.size(); i++) {
    long long l = a[i] - a[i - 1] - 1;
    for (int j = 1; j < l; j++) res += j * C2(l - j);
  }
  return res;
}
long long count02(vector<int> a) {
  long long res = 0;
  for (int i = 1; i < a.size() - 1; i++) {
    for (int j = a[i - 1] + 1; j < a[i]; j++) {
      res += (j - a[i - 1]) * C2(a.back() - j - 1);
    }
  }
  return res;
}
int getInd(const vector<int>& b, int x) {
  return lower_bound(b.begin(), b.end(), x) - b.begin();
}
long long f2(int l1, int r1, int l2, int r2) {
  return (l1 - l2) * 1ll * (r2 - r1);
}
long long f(int l1, int r1, int l2, const set<int>& S) {
  int r2 = *S.upper_bound(r1);
  return f2(l1, r1, l2, r2);
}
long long sum(long long x) { return x * (x + 1) / 2; }
long long sum2(long long x) { return x * (x + 1) * (x + x + 1) / 6; }
long long g2(int l1, int r1, int l2, int r2) {
  long long v = l1 - l2, w = r2 - r1 - 1;
  return v * (sum2(w) + sum(w)) / 2;
}
long long g3(int l1, int r1, int l2, int r2, int t) {
  long long r = 0;
  long long v = l1 - l2, w = r2 - r1 - 1;
  for (int i = 0; i <= w; i++) r += C2(t - i - 1 - r1);
  return v * r;
}
long long g(int l1, int r1, int l2, const set<int>& S) {
  int r2 = *S.upper_bound(r1);
  return g2(l1, r1, l2, r2);
}
int main() {
  cin.sync_with_stdio();
  cout.sync_with_stdio();
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> a[i];
    isGood[i] = good(a[i]);
    if (isGood[i]) b.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  for (int i = 0; i < (int)(n); ++i)
    if (isGood[i])
      a[i] = getInd(b, a[i]);
    else
      a[i] = -1;
  vector<int> posGood(1, -1);
  for (int i = 0; i < (int)(n); ++i)
    if (a[i] >= 0) {
      listOcc[a[i]].push_back(i);
      posGood.push_back(i);
    }
  int m = posGood.size();
  posGood.push_back(n);
  long long ans = count02(posGood);
  for (int r1 = 1; r1 < m; r1++) {
    long long curQ = 0;
    set<int> banned;
    set<int> usedGood;
    banned.insert(n);
    {
      int ind = posGood[r1];
      banned.insert(ind);
      usedGood.insert(a[ind]);
      for (int i = getInd(listOcc[a[ind]], ind) + 1; i < listOcc[a[ind]].size();
           i++) {
        banned.insert(listOcc[a[ind]][i]);
      }
    }
    {
      set<int>::iterator it = banned.begin();
      it++;
      while (*it != n) {
        set<int>::iterator itn = it;
        itn++;
        long long l = *itn - *it - 1;
        curQ += C2(l);
        it = itn;
      }
    }
    ans +=
        curQ * f2(posGood[r1], posGood[r1], posGood[r1 - 1], posGood[r1 + 1]);
    ans += g3(posGood[r1], posGood[r1], posGood[r1 - 1], posGood[r1 + 1],
              *banned.upper_bound(posGood[r1]));
    for (int l1 = r1 - 1; l1 >= 1; l1--) {
      if (usedGood.find(a[posGood[l1]]) == usedGood.end()) {
        usedGood.insert(a[posGood[l1]]);
        int ind = posGood[l1];
        for (int i = getInd(listOcc[a[ind]], ind) + 1;
             i < listOcc[a[ind]].size(); i++) {
          int x = listOcc[a[ind]][i];
          set<int>::iterator it1 = banned.begin();
          it1++;
          if (x < *it1) {
            curQ += C2(*it1 - x - 1);
          } else {
            set<int>::iterator it = banned.lower_bound(x);
            set<int>::iterator itp = it;
            itp--;
            curQ -= C2(*it - *itp - 1);
            curQ += C2(x - *itp - 1);
            curQ += C2(*it - x - 1);
          }
          banned.insert(x);
        }
      }
      ans +=
          curQ * f2(posGood[l1], posGood[r1], posGood[l1 - 1], posGood[r1 + 1]);
      ans += g3(posGood[l1], posGood[r1], posGood[l1 - 1], posGood[r1 + 1],
                *banned.upper_bound(posGood[r1]));
    }
  }
  cout << ans << endl;
  return 0;
}
