#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
long long int tmp = 85;
long long int a[MAXN], b[MAXN], ind[MAXN];
vector<long long int> o;
long long int n, d, x;
long long int getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
int main() {
  cin >> n >> d >> x;
  for (long long int i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (long long int i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (long long int i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
  for (int i = 0; i < n; i++) {
    ind[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == 1) {
      o.push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    long long int cur = n;
    bool check = false;
    while (cur >= 0 and cur >= n - tmp) {
      if (ind[cur] <= i and b[i - ind[cur]] == 1) {
        cout << cur << endl;
        check = true;
        break;
      }
      cur--;
    }
    if (check == true) {
      continue;
    }
    long long int cur_ans = 0;
    for (int j = 0; j < o.size(); j++) {
      if (o[j] < i) {
        cur_ans = max(cur_ans, a[i - o[j]]);
      }
    }
    cout << cur_ans << endl;
  }
}
