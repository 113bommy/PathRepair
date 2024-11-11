#include <bits/stdc++.h>
using namespace std;
struct st {
  int first, second, third, fourth;
};
bool cmp(st st1, st st2) { return (st1.first < st2.first); }
long long i, j, k, n, x, z, c, sum, sum1 = 1;
st v[3000000];
int main() {
  cin >> k;
  for (i = 0; i < k; i++) {
    cin >> n;
    int a[200009];
    sum = 0;
    for (j = 0; j < n; j++) {
      scanf("%d", &a[j]);
      sum += a[j];
    }
    for (j = 0; j < n; j++) {
      v[c].first = sum - a[j];
      v[c].second = sum;
      v[c].third = j + 1;
      v[c].fourth = i + 1;
      c++;
    }
  }
  stable_sort(v, v + c, cmp);
  for (i = 0; i < c - 1; i++)
    if (v[i].first == v[i + 1].first && v[i].fourth != v[i + 1].fourth) {
      cout << "YES" << endl;
      cout << v[i].fourth << " " << v[i].third << endl;
      cout << v[i + 1].fourth << " " << v[i + 1].third << endl;
      return 0;
    }
  cout << "NO";
  return 0;
}
