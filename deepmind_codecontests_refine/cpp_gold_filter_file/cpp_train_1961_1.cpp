#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
using namespace std;int f(long n){int p=log10(n);return 9*p+(int)(n/pow(10,p))-1;}int main(){long n;cin>>n;cout<<f(++n)<<endl;}