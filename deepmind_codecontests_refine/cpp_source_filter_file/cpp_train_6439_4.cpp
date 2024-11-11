#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;string ans;
  cin >>a>>b;
  if(a==1)a=14;
  if(b==1)b=14;
  if(a>b)ans="Alice"
  if(a<b)ans="Bob"
  if(a==b)ans="Draw";
  cout << ans << endl;
}