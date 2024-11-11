#include <bits/stdc++.h>
using namespace std;
double sampleProb[2010];
int main() {
  int v;
  scanf("%d", &v);
  while (v--) {
    for (int i = 0; i <= 2000; i++) sampleProb[i] = 0;
    int sz = 250;
    vector<int> sample(sz);
    bool done = false;
    double mid = 0;
    for (int i = 0; i < sz; i++) {
      scanf("%d", &sample[i]);
      mid += sample[i];
      if (sample[i] > 2000) {
        if (!done) puts("poisson");
        done = true;
      }
    }
    mid /= sz;
    if (done) continue;
    int num = ceil(mid);
    int offs = ceil(mid / 5);
    int in = 0;
    for (int i = 0; i < sz; i++) {
      if (sample[i] >= num - offs && sample[i] <= num + offs) in++;
    }
    if (in > 175)
      cout << "poisson" << endl;
    else
      cout << "uniform" << endl;
  }
  return 0;
}
