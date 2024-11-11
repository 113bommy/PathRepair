n=int(input())
A1=[int(i) for i in input().split()]
A2=[int(i) for i in input().split()]
s=0
for i in range(n):
  t=sum(A1[:i+1])+sum(A2[i:])
  s=max(s,t)
print(s)