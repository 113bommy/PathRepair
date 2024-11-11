#include<bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<pair<int, int>> A;
  for(int i=0; i<N; i++){
    int a; cin >> a;
    A.push_back({a, i});
  }
  sort(A.begin(), A.end());
  int ans = 0;
  for(int i=0; i<N; i++){
    if((A[i].second - i) % 2 != 0) ans++;
  }
  cout << (ans+1)/2 << endl;
  return 0;
}
