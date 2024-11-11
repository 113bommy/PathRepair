#include <bits/stdc++.h>
#include<set>
using namespace std;
 
int main() {
  set<int> S;
  int N;
  cin>>N;
  for(int i = 0; i<N; i+=1) {
    int d;
    cin>>d;
    S.insert(d);
  }
  cout<<S.size()<<endl;
}