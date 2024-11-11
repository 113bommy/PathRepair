#include<bits/stdc++.h>
using namepspace std;
int main(){
	int k , a , b;
    cin >> k >> a >> b;
    int q = b/k;
    if(k*q >= a)
    	cout<<"OK";
       else
     cout<<"NG";
}