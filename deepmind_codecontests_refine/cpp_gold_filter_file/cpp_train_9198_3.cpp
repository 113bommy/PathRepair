#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void f(int N, int K) {
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (K == 0) exit(0);
      K--;
      cout << i + 1;
      for (int x = 0; x < i; x++) {
        cout << " " << v[x];
      }
      cout << " " << v[j] << endl;
    }
  }
}
int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  f(N, K);
}
