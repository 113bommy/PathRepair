#include <iostream>
#include <vector>
using namespace	std;

int main() {
  int K;
  vector<int> c;

  while(1) {
    int sum	= 0;
    cin >> K;
    if(K == 0)
      break;
    for(int i = 0; i < K*(K-1)/2; i++) {
      int C;
      cin >> C;
      sum += C;
      c.push_back(C);
    }

    cout << sum/(K-1) << endl;
  }

  return 0;
}

