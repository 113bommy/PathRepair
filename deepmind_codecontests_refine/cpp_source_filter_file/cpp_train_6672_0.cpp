#include <bits/stdc++.h>
using namespace std;
struct rect {
  long long width;
  long long height;
};
int main() {
  bool y = 1;
  long long nOfRect;
  cin >> nOfRect;
  rect rectangle[nOfRect];
  for (long long i = 0; i < nOfRect; i++) {
    cin >> rectangle[i].width >> rectangle[i].height;
    if (i == 0) {
      if (rectangle[i].width < rectangle[i].height)
        swap(rectangle[i].width, rectangle[i].height);
    } else if (rectangle[i].width < rectangle[i].height &&
               rectangle[i].height < rectangle[i - 1].width)
      swap(rectangle[i].width, rectangle[i].height);
    else if (rectangle[i].width > rectangle[i].height &&
             rectangle[i].width > rectangle[i - 1].width)
      swap(rectangle[i].width, rectangle[i].height);
    else if (rectangle[i].width > rectangle[i - 1].width)
      y = 0;
  }
  if (y)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
