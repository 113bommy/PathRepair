#include<bits/stdc++.h>
using namespace std;
int main (){
  int x,,y,z;
  scanf("%d %d %d",&x,&y,&z);
  if((x==y&&x!=z)||(x==z&&x!=y)||(y==z&&z!=x))cout<<"Yes";
  else cout<<"No";
  return 0;
}