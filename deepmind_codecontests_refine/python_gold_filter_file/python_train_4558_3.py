# Fast IO (only use in integer input) or take care about string
 
import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
 
N = int(input())
 
ans = 0
for i in range(N):
  ans += (N-i) * (i+1)
for _ in range(N-1):
  a,b = map(int,input().split())
  if a > b:
    c = a
    a = b
    b = c
  ans -= a * (N - b + 1)
print(ans)