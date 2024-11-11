#include <bits/stdc++.h>
using namespace std;
struct Skill {
  long long value;
  int num;
};
bool com1(const Skill& s1, const Skill& s2) { return s1.value < s2.value; }
bool com2(const Skill& s1, const Skill& s2) { return s1.num > s2.num; }
int main() {
  int n, cf, cm;
  long long A, m;
  long long result = -1, curPefert = -1, ansMin, tmpmin, numOfmin = 0;
  long long v;
  Skill ski;
  cin >> n >> A >> cf >> cm >> m;
  vector<Skill> skill;
  vector<long long> sumOfSkill;
  skill.clear();
  sumOfSkill.clear();
  int i = n;
  while (i--) {
    cin >> v;
    ski.value = v;
    ski.num = i;
    skill.push_back(ski);
  }
  sort(skill.begin(), skill.end(), com1);
  sumOfSkill.push_back(0);
  for (i = 0; i < n; i++) {
    sumOfSkill.push_back(sumOfSkill[i] + skill[i].value);
  }
  int j;
  for (j = 0, i = 0; i <= n; i++) {
    int tmpm = m;
    if (tmpm + sumOfSkill[n] - sumOfSkill[i] < (n - i) * A) continue;
    long long tmpresult = (n - i) * cf;
    tmpm -= ((n - i) * A - sumOfSkill[n] + sumOfSkill[i]);
    for (; j < i;) {
      if (tmpm + sumOfSkill[j] >= skill[j].value * j)
        ++j;
      else
        break;
    }
    if (j == 0)
      tmpmin = A;
    else
      tmpmin = min((tmpm + sumOfSkill[j]) / j, A);
    tmpresult += tmpmin * cm;
    if (tmpresult > result) {
      result = tmpresult;
      curPefert = i;
      ansMin = tmpmin;
      numOfmin = j - 1;
    }
  }
  for (i = 0; i <= numOfmin; i++) {
    skill[i].value = ansMin;
  }
  for (i = curPefert; i < n; i++) {
    skill[i].value = A;
  }
  sort(skill.begin(), skill.end(), com2);
  cout << result << '\n';
  for (i = 0; i < n; i++) {
    cout << skill[i].value << ' ';
  }
  return 0;
}
