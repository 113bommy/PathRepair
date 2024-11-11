#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >>N;
  vector<tuple<strings,int,int>> a;
  for(int i=1;i<=N;i++){
    string s;
    int p;
    cin >> s >> p;
    p = -p;
    a.push_back(tie(s,p,i));
  }
  
  sort(a.begin(),a.end());
  for(int i=0;i<N;i++){
    cout << get<2>(a[i]) <<endl;
  }
}
