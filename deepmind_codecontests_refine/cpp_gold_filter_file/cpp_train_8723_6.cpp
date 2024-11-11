#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int i;
 cin >> N;
 int a[N];
 long long int odd=0;
 for(i=0;i<N;i++)cin >> a[i];
 for(i=0;i<(N-1)/2;i++){
   odd += a[2*i];
   odd -= a[2*i+1];
 }
 odd += a[N-1];
 for(i=0;i<(N-1)/2;i++){
   cout << odd << " " << 2*a[2*i]-odd << " ";
   odd -= 2*a[2*i];
   odd += 2*a[2*i+1];
   }
 cout << odd << endl;
 }