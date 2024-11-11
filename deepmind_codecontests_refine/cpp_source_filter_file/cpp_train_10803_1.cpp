#include<bits/stdc++.h>
using namespace std;
int main(){long N,x=0;cin>>N;
           for(long i=2;i<sqrt(N)+1;i++)
           {if(N%i==0){int a=0;while(N%i==0){a++;N/=i;}
int b=1,c=1;while(a>b){c++;b+=c;}if(a!=b)c--;x+=c;
                      }if(N!=1)x++;cout<<x<<endl;}                 