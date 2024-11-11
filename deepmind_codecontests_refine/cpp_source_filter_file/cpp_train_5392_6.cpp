#include <iostream>
#include <string>

using namespace std;

int main () {
   int N;
   cin>>N;
   string S;
   cin>>S;
   if ((N%2==0)) and (S.compare(0,N/2,S,N/2,N/2)==0)
           cout<<"Yes";
   else
       cout<<"No";
   return 0;}
