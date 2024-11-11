#include <bits/stdc++.h>
using namespace std;
unsigned long long fakultaet(unsigned long long n) {
  return (n == 1 || n == 0) ? 1 : fakultaet(n - 1) * n;
}
int main() {
  ios_base::sync_with_stdio(false);
  string n, a;
  cin >> n >> a;
  vector<long long> result;
  for (long long i = (0); i < ((long long)a.length()); i++) {
    if (a.at(i) == '9') {
      result.push_back(7);
      result.push_back(3);
      result.push_back(3);
      result.push_back(2);
    }
    if (a.at(i) == '8') {
      result.push_back(7);
      result.push_back(2);
      result.push_back(2);
      result.push_back(2);
    }
    if (a.at(i) == '7') {
      result.push_back(7);
    }
    if (a.at(i) == '6') {
      result.push_back(5);
      result.push_back(3);
    }
    if (a.at(i) == '5') {
      result.push_back(5);
    }
    if (a.at(i) == '4') {
      result.push_back(3);
      result.push_back(2);
      result.push_back(2);
    }
    if (a.at(i) == '3') {
      result.push_back(3);
    }
    if (a.at(i) == '2') {
      result.push_back(2);
    }
  }
  sort(result.begin(), result.end());
  for (long long i = (result.size()) - 1; i >= (0); i--) {
    cout << result[i];
  }
  cout << endl;
}
