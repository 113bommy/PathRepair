#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[6];
int res[6];
map<long long, long long> mark;
bool comp(long long a, long long b) { return a > b; }
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  std::vector<pair<int, int> > v;
  for (int i = 0; i < 5; i++) {
    cin >> b[i];
    mark[b[i]] = i;
  }
  sort(b, b + 5, comp);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int temp = a[i];
    sum += temp;
    for (int j = 0; j < 5; j++) {
      res[j] += sum / b[j];
      sum = sum % b[j];
    }
  }
  for (int i = 0; i < 5; i++) {
    a[i] = mark[b[i]];
  }
  for (int i = 0; i < 5; i++) {
    cout << res[a[i]] << ' ';
  }
  cout << endl;
  cout << sum << endl;
}
