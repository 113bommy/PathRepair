#include<bits/stdc++.h>
using namespace std;
int main(){
int s,k;
int count =0;
cin >>k>>s;
for(int x=0;x<=k;x++)
{
for( int y=0;y<=k;y++)
{
int z=s-(x+y);
if(z>=0&&z<=k)
count ++;
}
}
cout<<count <<endl;
}



}