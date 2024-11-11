#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a{}, b{}, c{}, d{};
  cin >> a >> b >> c >> d;
  long long int misha = max((3 * a) / 10, (a - (a * c) / 250));
  long long int vasya = max((3 * d) / 10, (b - (b * d) / 250));
  if (misha > vasya)
    cout << "Misha";
  else if (vasya > misha)
    cout << "Vasya";
  else
    cout << "Tie";
}
