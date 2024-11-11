import sys
input=sys.stdin.readline
N=int(input())
S=input()
w=S.count('.')
c=w
for i in range(N):
  if S[i]=='.':
    w-=1
  else:
    w+=1
  c=min(c,w)
print(c)