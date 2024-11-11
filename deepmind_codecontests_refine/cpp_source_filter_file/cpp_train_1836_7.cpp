#include <bits/stdc++.h>
using namespace std;
int d(int n, int n2) {
  int i, j, sum = 0;
  for (i = n;; i++) {
    if (i == n2) break;
    if (i == 12) i = 1;
    sum++;
  }
  return sum;
}
int main(void) {
  string aa[] = {"C",  "C#", "D",  "D#", "E", "F",
                 "F#", "G",  "G#", "A",  "B", "H"};
  int i, j, k, l, a, b, c;
  string s1, s2, s3;
  vector<int> as;
  cin >> s1 >> s2 >> s3;
  for (i = 0; i < 12; i++)
    if (s1 == aa[i]) {
      as.push_back(i + 1);
      break;
    }
  for (i = 0; i < 12; i++)
    if (s2 == aa[i]) {
      as.push_back(i + 1);
      break;
    }
  for (i = 0; i < 12; i++)
    if (s3 == aa[i]) {
      as.push_back(i + 1);
      break;
    }
  sort(as.begin(), as.end());
  a = d(as[0], as[1]);
  b = d(as[1], as[2]);
  if (a == 4 && b == 3) {
    cout << "major\n";
    return 0;
  } else if (a == 3 && b == 4) {
    cout << "minor\n";
    return 0;
  }
  a = d(as[1], as[2]);
  b = d(as[2], as[0]);
  if (a == 4 && b == 3) {
    cout << "major\n";
    return 0;
  } else if (a == 3 && b == 4) {
    cout << "minor\n";
    return 0;
  }
  a = d(as[2], as[0]);
  b = d(as[0], as[1]);
  if (a == 4 && b == 3) {
    cout << "major\n";
    return 0;
  } else if (a == 3 && b == 4) {
    cout << "minor\n";
    return 0;
  }
  cout << "strange\n";
  return 0;
}
