#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i=0;i<N;i++){
    cin >> v[i];
  }
  sort(v.begin(),v.end());
  cout << v[N-1]-v[0] << endl;
}