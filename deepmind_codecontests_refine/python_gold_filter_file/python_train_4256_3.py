N=int(input())
L=list(map(int,input().split()))
L.sort()
S=0
for i in L[::2]:
  S=S+i
print(S)