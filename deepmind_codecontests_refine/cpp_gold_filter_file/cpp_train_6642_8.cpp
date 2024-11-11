#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;cin>>a;
  int l=a/100,r=a%100;
  bool ym=true,my=true;
  if(l>12||l<=0)my=false;
  if(r>12||r<=0)ym=false;
  string ans;
  if(ym&&my)ans="AMBIGUOUS";
  if(ym&&!my)ans="YYMM";
  if(!ym&&my)ans="MMYY";
  if(!my&&!ym)ans="NA";
  cout<<ans<<endl;
}