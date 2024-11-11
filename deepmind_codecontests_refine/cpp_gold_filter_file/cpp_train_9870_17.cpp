#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a>=13){cout<<b;return 0;}
    if(a<13){if(a>5){cout<<b/2;}else{cout<<0;}}
}