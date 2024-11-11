N=int(input())
p=list(map(int,input().split()))
s=set()
z=0
for i in range(N):
  p[i]//=400
  if p[i]<8:
    s.add(p[i])
  else:
    z+=1
print(max(1,len(s)),end=' ')
print(len(s)+z)