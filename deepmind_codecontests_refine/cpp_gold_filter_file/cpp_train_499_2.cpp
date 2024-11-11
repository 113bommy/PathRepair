#include<bits/stdc++.h>
using namespace std;

int a,b,c,x,y;
int main(){
  cin >> a >> b >> c >> x >> y;
  int mini = INT_MAX;
  for(int t=0;t<=100000;t++){
    mini = min(mini, 2 * t * c + max(0, x-t) * a + max(0, y-t) * b);
  }
  cout << mini << endl;
}
  