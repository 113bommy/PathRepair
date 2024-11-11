#include <bits/stdc++.h>
using namespace std;
namespace {
bool compareInterval(pair<long long, long long> vec1,
                     pair<long long, long long> vec2) {
  return (vec1.first > vec2.first);
}
}  // namespace
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<pair<long long, long long>> vec(n);
  for (long long i = 0; i < n; i++) {
    cin >> vec[i].first;
    vec[i].second = i + 1;
  }
  sort(vec.begin(), vec.end(), compareInterval);
  long long ops = 0;
  for (long long i = 0; i < n; i++) {
    ops += vec[i].first * i + 1;
  }
  cout << ops << "\n";
  for (long long i = 0; i < n; i++) {
    cout << vec[i].second << " ";
  }
  return 0;
}
