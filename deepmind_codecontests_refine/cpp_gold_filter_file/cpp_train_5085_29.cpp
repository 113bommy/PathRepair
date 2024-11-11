#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[3];
  for(auto &i:a) cin >> i;
  sort(a,a+3);
  cout << a[0]+a[1] << endl;
}
