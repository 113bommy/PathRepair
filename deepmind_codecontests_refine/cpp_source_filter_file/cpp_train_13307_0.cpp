#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n;
cin>>n;
string S[n];
map<char,ll>m;
rep(i,n){
  cin>>S[i];
  m[S[i][0]]++;
}
char a[5]={'M','A','R','C','H'};
ll count=0;
for(int i=0;i<3;i++){
  for(int j=i+1;j<4;j++){
    for(int k=j+1;k<5;k++){

count+=ll(m[a[i]]*m[a[j]]*m[a[k]]);

    }
  }
}


cout<<count<<endl;
  return 0;
}
