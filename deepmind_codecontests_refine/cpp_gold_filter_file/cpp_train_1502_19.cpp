#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(const T& t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, " "));
  cout << endl;
}
template <typename T>
void print2d(const T& t) {
  std::for_each(t.cbegin(), t.cend(), print<typename T::value_type>);
}
long long cb = 0, cs = 0, cc = 0;
long long nb, ns, nc;
long long pb, ps, pc;
long long r;
long long price(long long num) {
  long long priceb = max((long long)0, num * cb - nb) * pb;
  long long prices = max((long long)0, num * cs - ns) * ps;
  long long pricec = max((long long)0, num * cc - nc) * pc;
  long long final = priceb + prices + pricec;
  return final;
}
int main() {
  string input;
  cin >> input;
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> r;
  for (long long i = 0; i < input.size(); i++) {
    if (input[i] == 'B')
      cb++;
    else if (input[i] == 'C')
      cc++;
    else
      cs++;
  }
  long long low = 0;
  long long high = 1e13;
  long long mid;
  long long ans;
  while (low <= high) {
    mid = low + (high - low) / 2;
    long long need = price(mid);
    if (need == r) {
      cout << mid << endl;
      return 0;
    }
    if (need > r) {
      high = mid - 1;
    } else {
      ans = mid;
      low = mid + 1;
    }
  }
  cout << ans << endl;
}
