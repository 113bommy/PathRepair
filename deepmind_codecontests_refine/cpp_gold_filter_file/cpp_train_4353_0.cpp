#include <bits/stdc++.h>
using namespace std;

int main() {
  char in[120];
  pair<pair<string,int>,int> p[110];
  int a;scanf("%d",&a);
  for(int i=0;i<a;i++){
    int t;scanf("%s%d",in,&t);
    string tmp=in;
    p[i]=make_pair(make_pair(in,-t),i);
  }
  sort(p,p+a);
  for(int i=0;i<a;i++)printf("%d\n",p[i].second+1);
}