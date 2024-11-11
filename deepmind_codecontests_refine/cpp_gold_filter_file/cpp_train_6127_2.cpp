#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N, M;
  cin >> N >> M;
  cout << min(M, N + M / 2) / 2 << endl;
}