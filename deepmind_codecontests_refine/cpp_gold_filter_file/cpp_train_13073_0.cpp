#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, c;
int bs1(int left, int right, int key, int status) {
  int middle = (left + right) / 2;
  if (left == right)
    return 0;
  else if (right - left == 1) {
    if (status == 0) {
      if (b[left] >= key)
        return left;
      else
        return right;
    } else {
      if (b[left] > key)
        return left;
      else
        return right;
    }
  } else {
    if (b[middle] > key)
      return bs1(left, middle, key, status);
    else
      return bs1(middle, right, key, status);
  }
}
int main() {
  int n, i, counter1 = 0, counter2 = 0, index;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  for (i = 0; i < s1.size(); i++) a.push_back(s1[i] - 48);
  for (i = 0; i < s2.size(); i++) {
    b.push_back(s2[i] - 48);
    c.push_back(s2[i] - 48);
  }
  sort(b.begin(), b.end());
  c = b;
  for (i = 0; i < n; i++) {
    if (a[i] > b.back()) {
      b.erase(b.begin());
      counter1++;
    } else {
      index = bs1(0, b.size() - 1, a[i], 0);
      b.erase(b.begin() + index);
    }
  }
  b = c;
  for (i = 0; i < n; i++) {
    if (a[i] >= b.back())
      b.erase(b.begin());
    else {
      index = bs1(0, b.size() - 1, a[i], 1);
      if (b[index] > a[i]) counter2++;
      b.erase(b.begin() + index);
    }
  }
  cout << counter1 << endl << counter2;
}
