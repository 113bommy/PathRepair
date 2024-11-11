N=int(input())
L=list(map(int,input().split()))
L.sort()
s=0
for i in range(N):
  s+=L[2*i]
print(s)
