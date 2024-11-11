#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> vect(N);
  int zeros = 0;
  int dernierdiffzero = 0;
  for (int i = 0; i < N; i++) {
    cin >> vect[i];
    if (vect[i] == 0)
      zeros++;
    else
      dernierdiffzero = i;
  }
  if (vect.size() == 0)
    cout << "NO" << endl;
  else if (zeros >= N)
    cout << "NO" << endl;
  else if (zeros == 0) {
    cout << "YES" << endl;
    cout << N << endl;
    for (int i = 0; i < N; i++) {
      cout << i + 1 << " " << i + 1 << endl;
    }
  } else {
    int a;
    a = 0;
    cout << "YES" << endl;
    vector<int> resx;
    vector<int> resy;
    int res = 0;
    for (int i = 0; i < N; i++) {
      if ((vect[i] + res != 0 && i < dernierdiffzero) || i == N - 1) {
        resx.push_back(a + 1);
        resy.push_back(i + 1);
        a = i + 1;
        res = 0;
      } else {
        res += vect[i];
      }
    }
    resy.push_back(N);
    cout << resx.size() << endl;
    for (int i = 0; i < resx.size(); i++) {
      cout << resx[i] << " " << resy[i] << endl;
    }
  }
  return 0;
}
