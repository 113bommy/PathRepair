#include<bits/stdc++.h>

using namespace std;

int main(){


int a,b,c,i;

cin>>a>>b>>c;

i=0;

for(int x=a;x<=b;x++){

if(c%x == 0) i++;
}

cout<<i<<endl;

return 0;

}
