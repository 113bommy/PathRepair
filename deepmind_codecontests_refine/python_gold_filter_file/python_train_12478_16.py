N=int(input())
S=input()
T=input()
for i in range(N+1):
  s = S+T[::-1][:i][::-1]
  if s[-N:]==T:print(N+i);break
