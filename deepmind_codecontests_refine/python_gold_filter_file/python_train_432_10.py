from math import gcd

n = int(input())

arr = list(map(int, input().split(' ')))

maxV = max(arr)

cd = -1

maxNum = -1

for i in range(n):
  if(arr[i] != maxV):
    maxNum = max(maxNum, arr[i])
    if(cd != -1):
      cd = gcd(cd, maxV - arr[i])
    else:
      cd = maxV - arr[i]

dif = maxV - maxNum

if(dif % cd) > 0:
  maxV += cd - (dif % cd)

delta = maxV * n - sum(arr)

y = delta // cd

print(y, cd)
