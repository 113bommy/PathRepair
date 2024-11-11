#include <bits/stdc++.h>
using namespace std;
const long long mxn = 2e5 + 10;
vector<long long> v;
long long arr[8];
void print(vector<long long> &v) {
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    printf("%lld ", v[i]);
  }
  printf("\n");
}
void print(vector<pair<long long, long long> > &v) {
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    printf("%lld %lld\n", v[i].first, v[i].second);
  }
}
void print(set<long long> s) {
  set<long long>::iterator itr;
  for (itr = s.begin(); itr != s.end(); ++itr) {
    cout << *itr << " ";
  }
  cout << endl;
}
void print(double d) { cout << fixed << setprecision(10) << d << endl; }
void from_file(void) {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void run() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  for (int i = (0); i < (n); ++i) {
    long long x;
    cin >> x;
    arr[x]++;
  }
  int c = 0;
  while (1) {
    if (arr[1] && arr[2] && arr[4]) {
      c++;
      arr[1]--;
      arr[2]--;
      arr[4]--;
      v.push_back(1);
      v.push_back(2);
      v.push_back(4);
      continue;
    }
    if (arr[1] && arr[2] && arr[6]) {
      c++;
      arr[1]--;
      arr[2]--;
      arr[6]--;
      v.push_back(1);
      v.push_back(2);
      v.push_back(6);
      continue;
    }
    if (arr[1] && arr[3] && arr[6]) {
      c++;
      arr[1]--;
      arr[3]--;
      arr[6]--;
      v.push_back(1);
      v.push_back(3);
      v.push_back(6);
      continue;
    }
    break;
  }
  if (c != n / 3)
    cout << -1 << endl;
  else {
    for (int i = 0; i < n; i += 3)
      cout << v[i] << " " << v[i + 1] << " " << v[i + 2] << endl;
  }
}
int main() {
  run();
  return 0;
}
