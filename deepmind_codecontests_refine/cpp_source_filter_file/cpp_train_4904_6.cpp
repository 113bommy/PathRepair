#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%lld", &n);
  long long cnt = n / 2;
  if (n & 1) {
    cnt++;
  }
  if (n <= 2) {
    printf("No\n");
  }
  if (n == 4) {
    printf("Yes\n");
    printf("2 2\n");
    printf("3 1 3 4\n");
  } else {
    vector<long long> v, v1;
    for (long long i = 1; i <= cnt; i++) {
      v.push_back(i);
    }
    for (long long j = cnt + 1; j <= n; j++) {
      v1.push_back(j);
    }
    printf("Yes\n");
    cout << v1.size() << ' ';
    for (long long i = 0; i < v1.size(); i++) {
      cout << v1[i] << ' ';
    }
    cout << endl;
    cout << v.size() << ' ';
    for (long long i = 0; i < v.size(); i++) {
      cout << v[i] << ' ';
    }
  }
}
