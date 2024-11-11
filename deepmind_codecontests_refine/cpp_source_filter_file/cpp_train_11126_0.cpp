#include <iostream>
using namespace std;
 
int main()
{
  int n;
  int min = 21, max = 0;
  int a, v;

  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a >> v;
    if (max < v){
      max = v;
      min = a;
    }
    else if (max == v){
      if (w1 > a){
        min = a;
      }
    }
  }
  cout << w1 << ' ' << max << endl;
  return (0);
}