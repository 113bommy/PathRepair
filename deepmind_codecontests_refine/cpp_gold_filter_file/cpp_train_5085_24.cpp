#include<bits/stdc++.h>
using namespace std;
int main(){
   int s[4];
   cin>>s[1]>>s[2]>>s[3];
   sort(s+1,s+1+3);
   cout<<s[1]+s[2];
}