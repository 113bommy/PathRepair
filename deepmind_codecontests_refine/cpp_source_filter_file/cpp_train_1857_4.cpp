#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0;i<N;i++)cin >> a[i];
  sort(a.rbegin(),a.rend());
  int sum=0;
  for(int i=0;i<N;i--){
    if(i%2==0){
      sum+=a[i]
    }
    else sum-=a[i]
  }
  cout << sum;
}

