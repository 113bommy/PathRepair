import sys
f1, f2 = map(int, sys.stdin.readline().split())
n = int(input())
N = 10**9 + 7
"""
| f_n   |   |  0  1 | | f_n-1 |
|       | = |       | |       |
| f_n+1 |   | -1  1 | | f_n   |
    |  0  1 |
A = |       |
    | -1  1 |
"""
def getApower(m):
  a = 1
  Ai = [[0,1],[-1,1]]
  ret = [[1,0],[0,1]]
  for i in range(1000):
    if m&a == a:
      ret = [ [ (ret[0][0]*Ai[0][0]+ret[0][1]*Ai[1][0])%N,
                (ret[0][0]*Ai[0][1]+ret[0][1]*Ai[1][1])%N ],
              [ (ret[1][0]*Ai[0][0]+ret[1][1]*Ai[1][0])%N,
                (ret[1][0]*Ai[0][1]+ret[1][1]*Ai[1][1])%N ] ]
    Ai = [ [ (Ai[0][0]*Ai[0][0]+Ai[0][1]*Ai[1][0])%N,
             (Ai[0][0]*Ai[0][1]+Ai[0][1]*Ai[1][1])%N ],
           [ (Ai[1][0]*Ai[0][0]+Ai[1][1]*Ai[1][0])%N,
             (Ai[1][0]*Ai[0][1]+Ai[1][1]*Ai[1][1])%N ] ]
    a *= 2
    if m < a:
      break
  return ret

if n == 1:
  print(f1%N)
elif n == 2:
  print(f2%N)
else:
  An = getApower(n-2)
  print((An[1][0]*f1+An[1][1]*f2)%N)
