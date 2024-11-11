#include<bits/stdc++.h>
using namespace std;

int a,b,c,x,y;
int main(){
  cin >> a >> b >> c >> x >> y;
  int mini = INT_MAX;
  for(int i=0;i<=100000;i++){
    mini = min(mini, 2 * t * c + max(0, x-t) * a + max(0, y-t) * b);
  }
  cout << mini << endl;
}
  