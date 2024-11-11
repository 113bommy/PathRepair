#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int num[100010];
int main() {
  long long ara[5];
  cin >> ara[0] >> ara[1] >> ara[2];
  sort(ara, ara + 3);
  if (ara[0] == 0) {
    cout << ara[2];
    return 0;
  }
  if ((ara[0] + ara[1]) % 2 == 0) {
    cout << ara[1];
  } else {
    cout << ara[2];
  }
}
