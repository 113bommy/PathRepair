# Fast IO (only use in integer input)

import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n = int(input())

a = list(map(int,input().split()))

s = sum(a)

s -= (n * n - n) // 2

k = s // n
r = s % n

ans = []

for i in range(n):
    curAns = k + i
    if r > i:
        curAns += 1
    ans.append(str(curAns))
print(" ".join(ans))