#include<bits/stdc++.h>
using namespace std;

string a;

int main()
{
	cin>>a;
    
    if(a[0]==a[1] || a[1]==a[2] || a[2]==a[3])
        cout<<"Bad";
    else
        cout<<"Good";
}
