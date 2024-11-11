#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, a;
  cin >> N >> M;
  vector<int> vec(N, 0);
  for(int i=0;i<2*M;i++){
    cin >> a;
    vec.at(a-1)++;
  }
  for(int i=0;i<N;i++){
    cout << vec.at(i) << endl;
  }
}
