#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int n;
int numLuckies;
int luckyLocations[1001];
map<int, vector<int> > luckyAppearances;
unsigned long long countForNonLuckyBeginnings(int i, map<int, int> &startPoints,
                                              unsigned long long currentNum) {
  map<int, int>::reverse_iterator it = startPoints.rbegin();
  unsigned long long lastGroupLen;
  int k;
  if (it != startPoints.rend()) {
    lastGroupLen = it->first - it->second + 1;
    k = luckyLocations[i] - (i > 0 ? luckyLocations[i - 1] : 0) - 1;
  } else {
    lastGroupLen = 0;
    k = 0;
  }
  return k * (currentNum - lastGroupLen * (lastGroupLen + 1ULL) / 2ULL +
              (lastGroupLen - k) * (lastGroupLen - k + 1ULL) / 2ULL) +
         k * (k - 1ULL) / 2ULL * (3ULL * lastGroupLen - 2ULL * k + 1) / 3ULL;
}
unsigned long long countGoodIntervalsForFixedI(int i) {
  unsigned long long currentSum, currentNum;
  unsigned long long lastGroupLen, toBeAdded;
  int tmp, val, startIndex, endIndex;
  map<int, int> startPoints;
  set<int> foundLuckies;
  startPoints.insert(make_pair(luckyLocations[i] - 1, 0));
  currentSum = 0;
  currentNum = luckyLocations[i] * (luckyLocations[i] + 1ULL) / 2;
  for (int j = i; j < numLuckies; ++j) {
    if (j > i && luckyLocations[j] - luckyLocations[j - 1] > 1) {
      tmp = luckyLocations[j] - luckyLocations[j - 1] - 1;
      currentSum += currentNum * tmp;
      toBeAdded = countForNonLuckyBeginnings(i, startPoints, currentNum);
      currentSum += tmp * toBeAdded;
    }
    val = arr[luckyLocations[j]];
    if (foundLuckies.find(val) == foundLuckies.end()) {
      const vector<int> &appearances = luckyAppearances[val];
      for (int k = 0; k < appearances.size(); ++k) {
        if (appearances[k] >= luckyLocations[i]) break;
        endIndex = startPoints.lower_bound(appearances[k])->first;
        startIndex = startPoints[endIndex];
        tmp = endIndex - startIndex + 1;
        currentNum -= tmp * (tmp + 1ULL) / 2ULL;
        if (appearances[k] < endIndex) {
          startPoints[endIndex] = (appearances[k] + 1);
          tmp = endIndex - appearances[k];
          currentNum += tmp * (tmp + 1ULL) / 2ULL;
        } else {
          startPoints.erase(endIndex);
        }
        if (appearances[k] > startIndex) {
          startPoints.insert(make_pair(appearances[k] - 1, startIndex));
          tmp = appearances[k] - startIndex;
          currentNum += tmp * (tmp + 1ULL) / 2ULL;
        }
      }
      foundLuckies.insert(val);
    }
    currentSum += currentNum;
    toBeAdded = countForNonLuckyBeginnings(i, startPoints, currentNum);
    currentSum += toBeAdded;
  }
  if (n - luckyLocations[numLuckies - 1] > 1) {
    tmp = n - luckyLocations[numLuckies - 1] - 1ULL;
    currentSum += currentNum * tmp;
    toBeAdded = countForNonLuckyBeginnings(i, startPoints, currentNum);
    currentSum += tmp * toBeAdded;
  }
  return currentSum;
}
unsigned long long countForNotLuckyInterval(int P, int R) {
  unsigned long long r[4] = {1ULL}, p[4] = {1ULL};
  for (int i = 1; i < 4; ++i) {
    r[i] = r[i - 1] * R;
    p[i] = p[i - 1] * P;
  }
  unsigned long long factors[7] = {2, 3, 4, 6, 8, 12, 24};
  unsigned long long tmp, tmp2, result, remFactor, toMultiply[5] = {};
  remFactor = 24;
  tmp = 1;
  for (int i = 0; i < 4; ++i) {
    toMultiply[i] = R + i;
  }
  for (int i = 0; i < 4; ++i) {
    tmp2 = toMultiply[i];
    for (int j = 6; j >= 0; --j) {
      if (!(remFactor % factors[j]) && !(tmp2 % factors[j])) {
        tmp2 /= factors[j];
        remFactor /= factors[j];
        break;
      }
    }
    tmp *= tmp2;
  }
  result = tmp;
  toMultiply[1] = P * (P - 1ULL);
  toMultiply[0] = (4ULL * R * (P + 1ULL) + 6ULL - 3ULL * P * (P - 1ULL));
  remFactor = 24;
  tmp = 1;
  for (int i = 0; i < 2; ++i) {
    tmp2 = toMultiply[i];
    for (int j = 6; j >= 0; --j) {
      if (!(remFactor % factors[j]) && !(tmp2 % factors[j])) {
        tmp2 /= factors[j];
        remFactor /= factors[j];
        break;
      }
    }
    tmp *= tmp2;
  }
  result -= tmp;
  return result;
}
unsigned long long solve() {
  int i, p, r, tmp, tmpP, tmpR;
  unsigned long long result = 0, tmp2;
  for (int i = 0; i < numLuckies; ++i) {
    tmp2 = countGoodIntervalsForFixedI(i);
    result += tmp2;
  }
  unsigned long long maxVal = 0, maxInd = -1;
  for (int i = 1; i < numLuckies; ++i) {
    p = luckyLocations[i - 1] + 1;
    r = luckyLocations[i] - 1;
    if (p <= r) {
      tmp2 = countForNotLuckyInterval(p, r);
      result += tmp2;
    }
  }
  if (numLuckies) {
    p = 0;
    r = luckyLocations[0] - 1;
    if (p <= r) {
      tmp2 = countForNotLuckyInterval(p, r);
      result += tmp2;
    }
    p = luckyLocations[numLuckies - 1] + 1;
    r = n - 1;
    if (p <= r) {
      tmp2 = countForNotLuckyInterval(p, r);
      result += tmp2;
    }
  } else {
    p = 0;
    r = n - 1;
    if (p <= r) {
      tmp2 = countForNotLuckyInterval(p, r);
      result += tmp2;
    }
  }
  return result;
}
bool isLucky(int n) {
  int tmp;
  while (n) {
    tmp = n % 10;
    if (tmp != 4 && tmp != 7) return false;
    n /= 10;
  }
  return true;
}
int main() {
  numLuckies = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
    if (isLucky(arr[i])) {
      luckyLocations[numLuckies++] = i;
      if (luckyAppearances.find(arr[i]) == luckyAppearances.end()) {
        luckyAppearances.insert(make_pair(arr[i], vector<int>()));
      }
      luckyAppearances[arr[i]].push_back(i);
    }
  }
  cout << solve() << endl;
  return 0;
}
