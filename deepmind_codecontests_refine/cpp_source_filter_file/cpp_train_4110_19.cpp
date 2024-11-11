#include <bits/stdc++.h>
using namespace std;
int main() {
  int misha_point, vasya_point;
  int misha_time, vasya_time;
  cin >> misha_point >> vasya_point;
  cin >> misha_time >> vasya_time;
  double misha_score, vasya_score;
  misha_score = max((3 * misha_point) / 10,
                    (misha_point - misha_point / 250) * misha_time);
  vasya_score = max((3 * vasya_point) / 10,
                    (vasya_point - vasya_point / 250) * vasya_time);
  if (misha_score == vasya_score)
    cout << "Tie\n";
  else
    misha_score > vasya_score ? cout << "Misha\n" : cout << "Vasya\n";
  return 0;
}
