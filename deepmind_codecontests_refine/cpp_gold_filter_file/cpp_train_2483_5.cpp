#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N>>M;
  vector<int> a(N+1);
  int i;
  for(i=0;i<2*M;i++){
    int s;
    cin >> s;
    a.at(s)++;
  }
  for(i=1;i<N+1;i++){
    cout<<a.at(i)<<endl;
  }
}
