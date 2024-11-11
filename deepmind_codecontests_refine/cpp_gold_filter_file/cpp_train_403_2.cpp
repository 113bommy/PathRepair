#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 25

int jewelry[MAX], lim[MAX];
int n;

void bubbleSort() {
  for(int i = 0; i < n; i++) {
    for(int j = n-1; j>i; j--) {
      if(lim[j-1] > lim[j]) {
	swap(lim[j-1], lim[j]);
	swap(jewelry[j-1], jewelry[j]);
      }
    }
  }  
}

int main() {
  bool success;
  int cur;

  while(cin >> n && n) {
    for(int i = 0; i < n; i++) {
      cin >> jewelry[i] >> lim[i];
    }
    bubbleSort();
    success = true;
    cur = 0;
    for(int i = 0; i < n && success; i++) {
      cur += jewelry[i];
      if(lim[i] < cur) success = false;
    }
    if(success) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}