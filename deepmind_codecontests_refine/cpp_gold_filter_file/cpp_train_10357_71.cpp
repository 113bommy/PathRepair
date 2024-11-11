#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int b = a / 10, c = a - b * 10;
  if (b == 9) {
    cout << "ninety";
  }
  if (b == 8) {
    cout << "eighty";
  }
  if (b == 7) {
    cout << "seventy";
  }
  if (b == 6) {
    cout << "sixty";
  }
  if (b == 5) {
    cout << "fifty";
  }
  if (b == 4) {
    cout << "forty";
  }
  if (b == 3) {
    cout << "thirty";
  }
  if (b == 2) {
    cout << "twenty";
  }
  if (b != 1 && b != 0 && a != 0) {
    if (a - b * 10 == 9) {
      cout << "-nine";
    }
    if (a - b * 10 == 8) {
      cout << "-eight";
    }
    if (a - b * 10 == 7) {
      cout << "-seven";
    }
    if (a - b * 10 == 6) {
      cout << "-six";
    }
    if (a - b * 10 == 5) {
      cout << "-five";
    }
    if (a - b * 10 == 4) {
      cout << "-four";
    }
    if (a - b * 10 == 3) {
      cout << "-three";
    }
    if (a - b * 10 == 2) {
      cout << "-two";
    }
    if (a - b * 10 == 1) {
      cout << "-one";
    }
  }
  if (b == 1) {
    if (a - b * 10 == 0) {
      cout << "ten";
    };
    if (a - b * 10 == 1) {
      cout << "eleven";
    };
    if (a - b * 10 == 2) {
      cout << "twelve";
    };
    if (a - b * 10 == 3) {
      cout << "thirteen";
    };
    if (a - b * 10 == 4) {
      cout << "fourteen";
    };
    if (a - b * 10 == 5) {
      cout << "fifteen";
    };
    if (a - b * 10 == 6) {
      cout << "sixteen";
    };
    if (a - b * 10 == 7) {
      cout << "seventeen";
    };
    if (a - b * 10 == 8) {
      cout << "eighteen";
    };
    if (a - b * 10 == 9) {
      cout << "nineteen";
    };
  }
  if (b == 0) {
    if (a - b * 10 == 0) {
      cout << "zero";
    };
    if (a - b * 10 == 1) {
      cout << "one";
    };
    if (a - b * 10 == 2) {
      cout << "two";
    };
    if (a - b * 10 == 3) {
      cout << "three";
    };
    if (a - b * 10 == 4) {
      cout << "four";
    };
    if (a - b * 10 == 5) {
      cout << "five";
    };
    if (a - b * 10 == 6) {
      cout << "six";
    };
    if (a - b * 10 == 7) {
      cout << "seven";
    };
    if (a - b * 10 == 8) {
      cout << "eight";
    };
    if (a - b * 10 == 9) {
      cout << "nine";
    };
  }
  cout << endl;
}
