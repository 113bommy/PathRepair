#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,N;
  cin >> a >> b >> N;

  int a[1000] = {0};
  int count1 = 0,count2 = 0;
  for(int i = a; i < b; i++){
    a[i] = 1;
    count1++;
  }

  int x,y;
  for(int i = 0; i < N; i++){
    cin >> x >> y;
    for(int i = x; i < y; i++){
      a[i] = 0;
    }
  }

  for(int i = 0; i < 1000; i++){
    if(a[i] == 1)count2++;
  }
  if(count1 == count2)cout << '0' << endl;
  else cout << '1' << endl;

  return 0;
}

