#include <bits/stdc++.h>
using namespace std;
long long int fact(long long int n) {
  long long int ans = 1;
  for (long long int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}
long sum(long long ara[], long n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += ara[i];
  }
  return sum;
}
int main() {
  int n, c;
  cin >> n >> c;
  vector<string> str;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    str.push_back(temp);
  }
  vector<pair<int, int> > vect;
  int f_upore1 = 0;
  int f_upore2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c; j++) {
      if (str[i][j] == '*') {
        vect.push_back(make_pair(i, j));
      }
      if (str[i][j] == '*' and f_upore1 == 0) {
        f_upore1 = 1;
        continue;
      }
      if (f_upore1 == 1 and f_upore2 == 0 and str[i][j] == '*' and
          vect[0].first == i) {
        f_upore2 = 1;
      }
    }
  }
  int ansr, ansc;
  if ((f_upore1 == 0 and f_upore2 == 1) or (f_upore1 == 1 and f_upore2 == 0)) {
    ansr = vect[0].first;
    if (vect[1].second == vect[0].second) {
      ansc = vect[2].second;
    } else {
      ansc = vect[1].second;
    }
  } else {
    ansr = vect[2].first;
    if (vect[0].second == vect[2].second) {
      ansc = vect[1].second;
    } else {
      ansc = vect[0].second;
    }
  }
  cout << ansr + 1 << " " << ansc + 1 << endl;
}
