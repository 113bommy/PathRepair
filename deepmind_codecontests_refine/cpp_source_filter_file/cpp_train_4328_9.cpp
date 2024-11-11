#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int l[N];
  int r[N];
  int suml = 0;
  int sumr = 0;
  int beauty = 0;
  for (int i = 0; i < N; i++) {
    cin >> l[i] >> r[i];
    suml = suml + l[i];
    sumr = sumr + r[i];
  }
  beauty = abs(suml - sumr);
  int ll, rr;
  int point;
  for (int i = 0; i < N; i++) {
    ll = suml - l[i] + r[i];
    rr = sumr - r[i] + l[i];
    if (abs(ll - rr) > beauty) {
      beauty = abs(ll - rr);
      point = i + 1;
    }
  }
  cout << point << endl;
}
