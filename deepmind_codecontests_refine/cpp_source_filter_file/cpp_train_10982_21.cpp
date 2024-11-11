#include <bits/stdc++.h>
using namespace std;
vector<int> hmm;
int main() {
  int n;
  scanf("%d", &n);
  for (int x = 2; x <= n; x++) {
    int pp = x, counts = 0;
    for (int i = 2; i * i <= pp; i++) {
      if (pp % i == 0) {
        counts++;
        while (pp % i == 0) pp = pp / i;
      }
    }
    if (counts <= 1) hmm.push_back(x);
  }
  printf("%d\n", hmm.size());
  for (int i = 0; i < hmm.size(); i++) printf("%d ", hmm[i]);
}
