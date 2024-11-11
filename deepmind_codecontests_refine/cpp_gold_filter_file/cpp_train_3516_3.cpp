#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<long long>a(n);
  long long s=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    s^=a[i];
  }
  for(int i=0;i<n;i++) cout<<(s^a[i])<<' ';
}