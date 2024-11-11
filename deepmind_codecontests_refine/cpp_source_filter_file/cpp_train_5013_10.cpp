#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const long long INF = std::numeric_limits<long long>::max();
const int MX = 100001;
const long double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270L;
template <typename T>
pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) {
  return pair<T, T>(a.first + b.first, a.second + b.second);
}
template <typename T>
pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) {
  return pair<T, T>(a.first - b.first, a.second - b.second);
}
template <typename T>
T operator*(const pair<T, T> &a, const pair<T, T> &b) {
  return (a.first * b.first + a.second * b.second);
}
template <typename T>
T operator^(const pair<T, T> &a, const pair<T, T> &b) {
  return (a.first * b.second - a.second * b.first);
}
bool check(std::string a) {
  for (int i = 1; i < a.size(); ++i) {
    if (abs(a[i] - a[i - 1]) == 1) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  std::string a;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    vector<int> kiek(27, 0);
    for (int j = 0; j < a.size(); ++j) kiek[int(a[j] - 'a')]++;
    std::vector<std::string> dal;
    for (int k = 0; k < 26; k++) {
      std::string nauj = "";
      if (!kiek[k]) continue;
      for (int j = 0; j < kiek[k]; ++j) nauj += char('a' + k);
      dal.push_back(nauj);
    }
    string gal = "";
    if (dal.size() == 1) {
      gal = dal[0];
      if (check(gal))
        cout << gal << '\n';
      else
        cout << "No answer\n";
    } else if (dal.size() == 2) {
      gal = dal[0] + dal[1];
      if (check(gal))
        cout << gal << '\n';
      else
        cout << "No answer\n";
    } else if (dal.size() == 3) {
      if (dal[0][0] - dal[1][0] == 1) {
        gal = dal[0] + dal[2] + dal[1];
      } else {
        gal = dal[2] + dal[0] + dal[1];
      }
      if (check(gal))
        cout << gal << '\n';
      else
        cout << "No answer\n";
    } else {
      if ((int)dal.size() & 1) {
        for (int l = 0; l < dal.size(); l += 2) gal += dal[l];
        for (int l = 1; l < dal.size(); l += 2) gal += dal[l];
      } else {
        for (int l = 1; l < dal.size(); l += 2) gal += dal[l];
        for (int l = 0; l < dal.size(); l += 2) gal += dal[l];
      }
      if (check(gal))
        cout << gal << '\n';
      else
        cout << "No answer\n";
    }
  }
}
