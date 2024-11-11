#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  vector<long long> flowers;
  scanf("%d", &N);
  flowers.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> flowers[i];
  }
  sort(flowers.begin(), flowers.end());
  long long smallN = 1, largeN = 1;
  for (int i = 0; i < N - 1; i++) {
    if (flowers[i] != flowers[i + 1]) {
      break;
    }
    smallN++;
  }
  for (int i = N - 1; i >= 1; i--) {
    if (flowers[i] != flowers[i - 1]) {
      break;
    }
    largeN++;
  }
  long long diff;
  long long num;
  diff = flowers[N - 1] - flowers[0];
  if (diff == 0) {
    for (int i = N - 1; i >= 0; i--) {
      num += (long long)i;
    }
  } else {
    num = largeN * smallN;
  }
  cout << diff << " " << num << endl;
  return 0;
}
