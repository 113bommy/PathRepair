#include <bits/stdc++.h>
using namespace std;
int get(int bit, int n) {
  if (n > bit)
    return 0;
  else if (n == 0 || n == bit)
    return 1;
  else if (n == 1 || n == bit - 1)
    return bit;
  else {
    return get(bit - 1, n) + get(bit - 1, n - 1);
  }
}
int main() {
  string s1, s2;
  int pos1, pos2, q, t;
  pos1 = pos2 = q = 0;
  cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == '+')
      pos1++;
    else if (s1[i] == '-')
      pos1--;
  }
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] == '+')
      pos2++;
    else if (s2[i] == '?')
      q++;
    else if (s2[i] == '-')
      pos2--;
  }
  t = pos1 - pos2;
  double ans = 0;
  if (t >= 0) {
    if (t == 0 && q % 2 == 0) {
      double temp = get(q, q / 2);
      ans = double(temp / pow(2, q));
    } else if ((q - t) % 2 == 0) {
      t += (q - t) / 2;
      double temp = get(q, t);
      ans = double(temp / pow(2, q));
    }
  } else if (t < 0) {
    t *= -1;
    if ((q - t) % 2 == 0) {
      t += (q - t) / 2;
      double temp = get(q, t);
      ans = double(temp / pow(2, q));
    }
  }
  cout << setprecision(12) << fixed << double(ans) << endl;
}
