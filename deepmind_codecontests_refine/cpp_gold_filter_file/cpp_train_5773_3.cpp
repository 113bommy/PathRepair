#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-10;
template <typename T, typename S>
vector<T>& operator<<(vector<T>& a, S b) {
  a.push_back(b);
  return a;
}
template <typename T>
void operator>>(vector<T>& a, int b) {
  while (b--)
    if (!a.empty()) a.pop_back();
}
bool isprime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long b_pow(long long x, long long n) {
  return n ? n == 1 ? x : b_pow(x, n >> 1) * b_pow(x, (n >> 1) + (n & 1)) : 1;
}
string itos(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
int main() {
  ios_base::sync_with_stdio(true);
  int w, h;
  bool sw = 0;
  vector<pair<int, int> > output;
  cin >> w >> h;
  if (h % 2 == 0) {
    sw = 1;
    swap(h, w);
  }
  for (int i = 0; i < w; i++) output.push_back(make_pair(i + 1, 1));
  for (int i = 0; i < w; i++) {
    if (i % 2 == 0)
      for (int j = 0; j < h - 1; j++) output.push_back(make_pair(w - i, j + 2));
    else
      for (int j = 0; j < h - 1; j++) output.push_back(make_pair(w - i, h - j));
  }
  output.push_back(make_pair(1, 1));
  if (min(h, w) == 1 && max(h, w) != 2) {
    cout << "1" << endl;
    cout << (sw ? h : w) << " " << (sw ? w : h) << " 1 1" << endl;
  } else if (w % 2) {
    cout << "1" << endl;
    cout << 1 << " " << (sw ? w : h) << " 1 1" << endl;
  } else {
    cout << "0" << endl;
  }
  if (sw)
    for (int i = 0; i < output.size(); i++)
      swap(output[i].first, output[i].second);
  for (int i = 0; i < output.size(); i++)
    cout << output[i].first << " " << output[i].second << endl;
}
