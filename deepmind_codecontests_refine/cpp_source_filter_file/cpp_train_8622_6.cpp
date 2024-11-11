#include<iostream>
#include<vector>
using namespace std;
int main(){
  int max=101010;
  vector<int> a(max,1)
  a[0]=0;
  a[1]=0;
  for(int i=2;i<max;++i){
    for(int j=i*2;j<max;j+=i) a[j]=0;
  }
  vector<int> a(max,0);
  for(int i=0;i<max;i++){
    if(a[i]==1&&a[(i+1)/2]) a[i]=1;
  }
  
  vector<int> s(max+1,0);
  for(int i=0;i<max;i++) s[i+1]=a[i]+s[i];
  
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    r++;
    cout<<s[r]-s[l]<<endl;
  }
  return 0;
}