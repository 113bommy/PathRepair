#include <bits/stdc++.h>
using namespace std;
void construct_first(int sum, list<int> &num);
void construct_next(int sum, int prevSum, list<int> &last) {
  if (sum > prevSum) {
    for (list<int>::reverse_iterator it = last.rbegin(); it != last.rend();
         ++it) {
      if (9 - *it <= sum - prevSum) {
        prevSum += (9 - *it);
        *it = 9;
      } else {
        *it += sum - prevSum;
        sum = prevSum;
      }
    }
    construct_first(sum - prevSum, last);
  } else {
    for (list<int>::reverse_iterator it = last.rbegin(); it != last.rend();
         ++it) {
      list<int>::reverse_iterator cit = it;
      cit++;
      if (*it == 0) {
        continue;
      }
      prevSum -= *it;
      *it = 0;
      if (cit == last.rend()) {
        last.push_front(1);
        prevSum++;
        break;
      }
      bool over = true;
      while (over) {
        if (*cit != 9) {
          *cit += 1;
          prevSum++;
          over = false;
        } else {
          prevSum -= *cit;
          *cit = 0;
          cit++;
          if (cit == last.rend()) {
            last.push_front(1);
            prevSum++;
            break;
          }
        }
      }
      if (over) {
        break;
      }
      if (prevSum < sum) {
        break;
      }
    }
    list<int>::reverse_iterator it = last.rbegin();
    while (prevSum < sum) {
      if (prevSum + 9 <= sum) {
        *it = 9;
        prevSum += 9;
      } else {
        *it = sum - prevSum;
        prevSum = sum;
      }
      it++;
    }
  }
}
void construct_first(int sum, list<int> &num) {
  while (sum >= 9) {
    num.push_back(9);
    sum -= 9;
  }
  if (sum > 0) {
    num.push_front(sum);
  }
}
void out(list<int> &num) {
  for (auto a : num) {
    cout << a;
  }
  cout << endl;
}
void solve_case() {
  int n;
  cin >> n;
  list<int> last;
  vector<int> sums;
  int prevSum = 0;
  for (int i = 0; i < n; i++) {
    int sum;
    cin >> sum;
    if (i == 0) {
      construct_first(sum, last);
    } else {
      construct_next(sum, prevSum, last);
    }
    prevSum = sum;
    out(last);
  }
}
int main(int argc, const char *argv[]) {
  ifstream in("./in.txt");
  if (0) {
    cin.rdbuf(in.rdbuf());
  }
  int testCount = 1;
  if (0) {
    cin >> testCount;
  }
  for (int i = 0; i < testCount; i++) {
    solve_case();
  }
  return 0;
}
