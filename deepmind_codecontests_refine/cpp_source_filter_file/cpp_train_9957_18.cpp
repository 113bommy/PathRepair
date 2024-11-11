#include <bits/stdc++.h>
using namespace std;
const int N = 300001;
long long n, k;
int divisorNum[N];
int preprocess(int n, int k) {
  for (int i = 0; i <= n; i++) {
    divisorNum[i] = 1;
  }
  int root = (int)sqrt(N);
  for (int i = 2; i <= root; i++) {
    int j = 2;
    int mul = i * j;
    while (mul <= N) {
      divisorNum[mul]++;
      j++;
      mul = i * j;
    }
  }
  int max = 0;
  for (int i = 2; i <= n; i++) {
    max += divisorNum[i];
  }
  if (max < k) {
    cout << "No" << endl;
    return 0;
  } else {
    int ktemp = 0;
    int maxN = 0;
    for (int i = 2; i <= n; i++) {
      ktemp += divisorNum[i];
      if (ktemp >= k) {
        maxN = i;
        break;
      }
    }
    cout << "Yes" << endl;
    ktemp = ktemp - k;
    int num = maxN;
    for (int i = 1; i <= maxN; i++) {
      if (ktemp - divisorNum[i] - maxN / i + 1 >= 0) {
        ktemp -= (divisorNum[i] + maxN / i - 1);
        divisorNum[i] = 0;
        num--;
      }
    }
    cout << num << endl;
    for (int i = 1; i <= maxN; i++) {
      if (divisorNum[i] > 0) {
        cout << i << " ";
      }
    }
    return 0;
  }
}
int main() {
  scanf("%I64d%I64d", &n, &k);
  return preprocess(n, k);
}
