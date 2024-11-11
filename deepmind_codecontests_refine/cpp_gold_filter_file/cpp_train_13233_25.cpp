#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    long long sum = 0;
    int maxx = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] > maxx) maxx = a[i], pos = i;
      sum += a[i];
    }
    int max2 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > max2 && i != pos) max2 = a[i];
    }
    sum -= maxx;
    vector<int> re;
    for (int i = 0; i < n; i++) {
      if ((pos != i) && (sum - a[i]) == maxx) {
        re.push_back(i);
      }
    }
    if (sum - max2 == max2) re.push_back(pos);
    printf("%d\n", re.size());
    if (re.size() == 0) cout << endl;
    for (int i = 0; i < re.size(); i++)
      printf("%d%c", re[i] + 1, i == (re.size() - 1) ? '\n' : ' ');
  }
}
