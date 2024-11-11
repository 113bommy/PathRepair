#include<iostream> 
#include<math.h>
using namespace std;
 int main()
 {
     long long int N,K,X=0;
     int i;
     cin>>N;
     for(i=1;i<=N;i++)
     {
         cin>>K;
         X ^= K;
     }
     if(X==0)
      cout<<"Yes";
      else
      cout<<"No";
 }
