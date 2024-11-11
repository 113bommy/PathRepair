#include <bits/stdc++.h>
using namespace std;

int main() {

int H,W,N;
 cin >> H >>W>>N;
 int a;
 if(H>N)a=(N+H-1)/H;
 else a=(N+W-1)/W;

 cout<<a<<endl;