#include <bits/stdc++.h>
using namespace std;
struct Student {
  int i, sk;
};
Student s[5002];
int sk[] = {0, 0, 0};
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    s[i].i = i;
    cin >> s[i].sk;
    sk[s[i].sk - 1]++;
  }
  sort(s + 1, s + n + 1,
       [](Student const &a, Student const &b) { return a.sk < b.sk; });
  int min = *min_element(sk, sk + 3);
  cout << min << '\n';
  for (int i = 1; i <= min; i++) {
    cout << s[i].i << ' ' << s[i + sk[0]].i << ' ' << s[i + sk[0] + sk[1]].i
         << '\n';
  }
  return 0;
}
