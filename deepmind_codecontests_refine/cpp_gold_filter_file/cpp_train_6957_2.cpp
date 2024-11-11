#include <bits/stdc++.h>
#include <sysexits.h>
using namespace std;

int main (){
string s ,t;
cin >>s >>t;
int x = stoi (s+ t );
for ( int i =1; i <=1000; i ++){
if ( i*i == x ){
puts (" Yes ");
return 0;
}
}
puts (" No ");
}
