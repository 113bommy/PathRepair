#include <bits/stdc++.h>
using namespace std;
int n, k, x, per;
vector<int> q, v, qq;
bool hw[1000];
vector<double> r;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    q.push_back(x);
  }
  int a;
  cin >> a;
  per = n / k;
  for (int i = 0; i < a; i++) {
    int sum = 0;
    for (int j = 0; j < per; j++) {
      cin >> x;
      sum += q[x - 1];
      hw[x - 1] = 1;
    }
    double avg = (sum + 0.0) / (per + 0.0);
    r.push_back(avg);
  }
  for (int i = 0; i < n; i++)
    if (hw[i] == 0) qq.push_back(q[i]);
  if (qq.size() > n - k * per) {
    sort(qq.begin(), qq.end());
    int sum = 0;
    for (int i = 0; i < per; i++) sum += qq[i];
    double avg = (sum + 0.0) / per;
    r.push_back(avg);
    reverse(qq.begin(), qq.end());
    sum = 0;
    for (int i = 0; i < per; i++) sum += qq[i];
    avg = (sum + 0.0) / per;
    r.push_back(avg);
  }
  sort(r.begin(), r.end());
  printf("%f %f", r.front(), r.back());
  return 0;
}
