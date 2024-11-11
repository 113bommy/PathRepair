#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int s;
 cin>>s;
 int l=s/100;
 int r=s%100;
 if(l>=1&&l<=12)
 {
     if(r>=1&&r<=12)
        cout<<"AMBIGUOUS";
     else
        cout<<"MMYY";
 }
 else if(r>=1&&r<=12)
    cout<<"YYMM";
 else
    cout<<"NA";


}
