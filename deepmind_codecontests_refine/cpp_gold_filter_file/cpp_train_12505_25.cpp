#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
  return {l.first + r.first, l.second + r.second};
}
typedef void (*callback_function)(void);
const long long INF64 = 1e18;
const long long INF32 = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  if (false) {
    freopen("A.in", "r", stdin);
    cerr << "Remember to switch INPUT_FILE off before submitting!" << endl
         << endl;
    freopen("A.out", "w", stdout);
  }
  auto beginProgram = chrono::steady_clock::now();
  {
    long long x;
    cin >> x;
    long long b = 1;
    while (b <= x && b * b <= x) {
      b++;
    }
    if (b <= x) {
      cout << b << ' ' << b << endl;
    } else {
      cout << -1 << endl;
    }
  }
  if (false) {
    auto endProgram = chrono::steady_clock::now();
    cerr << "Elapsed time (ms): "
         << chrono::duration_cast<chrono::milliseconds>(endProgram -
                                                        beginProgram)
                .count()
         << endl;
    system("gnome-open A.in");
    system("gnome-open A.correct");
    system("gnome-open A.out");
    fstream myAns("A.out");
    fstream correctAns("A.correct");
    string myLine, correctLine;
    long long lineIndex = 1;
    bool moreMyAns, moreCorrectAns;
    moreMyAns = (bool)getline(myAns, myLine);
    moreCorrectAns = (bool)getline(correctAns, correctLine);
    while (moreMyAns && moreCorrectAns) {
      cerr << lineIndex++ << "\t" << (myLine == correctLine ? "ok" : "WRONG")
           << endl;
      moreMyAns = (bool)getline(myAns, myLine);
      moreCorrectAns = (bool)getline(correctAns, correctLine);
    }
    if (moreMyAns) {
      cerr << "ERROR: My answer is too long! Excessive lines:" << endl;
      do {
        cerr << lineIndex++ << "\t" << myLine << endl;
      } while (getline(myAns, myLine));
    } else if (moreCorrectAns) {
      cerr << "ERROR: My answer is too short! Missing lines:" << endl;
      do {
        cerr << lineIndex++ << "\t" << correctLine << endl;
      } while (getline(correctAns, correctLine));
    }
    myAns.flush();
    myAns.close();
    correctAns.flush();
    correctAns.close();
  }
  return 0;
}
