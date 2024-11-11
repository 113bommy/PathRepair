#include <bits/stdc++.h>
using namespace std;
bool cheak[1003];
vector<int> vec;
void soe(int n) {
  cheak[0] = 1;
  cheak[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (cheak[i] != 1) {
      vec.push_back(i);
      long long k = 2;
      while (pow(i, k) <= n) {
        vec.push_back(pow(i, k));
        k++;
      }
      for (int j = 2 * i; j <= n; j += i) {
        cheak[j] = 1;
      }
    }
  }
}
int main() {
  long long n;
  cin >> n;
  soe(n);
  cout << vec.size() << endl;
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
}
