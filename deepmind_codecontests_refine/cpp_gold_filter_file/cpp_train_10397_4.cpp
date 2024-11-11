#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k,d[10]={},tmp;
  vector <int> dl;
  for(cin>>n>>k;cin>>tmp;dl.push_back(tmp));
  for(;;n++){
    for(int a=n;a;a/=10) for(int i=0;i<dl.size();i++) if(dl[i]==a%10) goto end;
    cout<<n<<endl;
    return 0;
  end:;
  }
}