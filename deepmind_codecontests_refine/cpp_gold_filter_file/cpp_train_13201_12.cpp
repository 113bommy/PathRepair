#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B; cin >> N >> A >> B;
  int a=0, ab=0, b=0;
  int tmp;
  for (int i=0; i<N; i++) {
    cin >> tmp;
    if (tmp <= A) a++;
    else if (tmp > B) b++;
    else ab++;
  }
  cout << min(a, min(ab, b)) << endl;
}