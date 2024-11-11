#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
long long sol;
long long A[maxn];
pair<long long, long long> query[maxn], k[maxn];
vector<long long> m;
vector<long long> n;
long long max1(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long bad(int l1, int l2, int l3) {
  return (n[l2] - n[l1]) * (m[l1] - m[l3]) > (n[l3] - n[l1]) * (m[l1] - m[l2]);
}
void computedp(int in, int fn) {
  if (in == fn) {
    sol = max1(sol, A[in]);
    return;
  }
  computedp(in, (in + fn) / 2);
  computedp((in + fn) / 2 + 1, fn);
  long long sum = 0;
  long long sumi = 0;
  n.clear();
  m.clear();
  for (int i = (in + fn) / 2; i >= in; i--) {
    sum += A[i];
    sumi += sum;
    m.push_back(-((in + fn) / 2 - i + 1));
    n.push_back(-(sumi));
    while (m.size() >= 3 && bad(m.size() - 3, m.size() - 2, m.size() - 1)) {
      m.erase(m.end() - 2);
      n.erase(n.end() - 2);
    }
  }
  sum = sumi = 0;
  int cont = 0;
  for (int i = (in + fn) / 2 + 1; i <= fn; i++) {
    sum += A[i];
    sumi += A[i] * (i - (in + fn) / 2);
    query[++cont].first = sum;
    query[cont].second = sumi;
  }
  stable_sort(query + 1, query + 1 + cont);
  int pos = 0;
  for (int i = 1; i <= cont; i++) {
    while (m.size() - 1 > pos && m[pos] * query[i].first + n[pos] >
                                     m[pos + 1] * query[i].first + n[pos + 1]) {
      pos++;
    }
    sol = max1(sol, -(m[pos] * query[i].first + n[pos]) + query[i].second);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  computedp(1, n);
  cout << sol;
  return 0;
}
