#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int> p(N,1);
  vector<int> r(N);
  r.at(0)=1;
  for(int i=0;i<M;i++){
int a,b;
    cin>>a>>b;
    a--,b--;
    if(r.at(a)==1){
r.at(b)=1;
    }
p.at(a)--;
    p.at(b)++;
    if(p.at(a)==0){
r.at(a)=0;
    }
  }
int Z=0;
for(int i=0;i<N;i++){
Z+=r.at(i);
}
cout<<Z<<endl;
}