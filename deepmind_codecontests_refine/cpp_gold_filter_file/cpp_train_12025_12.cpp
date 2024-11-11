#include <bits/stdc++.h>
using namespace std;
int N;
int sum = 0;
struct node {
  int a, p;
};
node tt[111111];
bool flag;
int pos;
int minn;
void solve() {}
int main() {
  cin >> N;
  flag = true;
  minn = 111;
  pos = N;
  long long sum = 0;
  for (int i = 1; i <= N; i++) {
    cin >> tt[i].a >> tt[i].p;
    if (flag) {
      sum += (tt[i].a * tt[i].p);
      flag = false;
      minn = tt[i].p;
    } else {
      if (tt[i].p > minn)
        sum += (tt[i].a * minn);
      else {
        minn = tt[i].p;
        sum += (tt[i].a * minn);
      }
    }
  }
  cout << sum << endl;
  return 0;
}
