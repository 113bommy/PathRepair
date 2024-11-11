n=int(input())
a=list(map(int,input().split()))
a.sort()
a.reverse()
j=[];x=-2
for i in range(n-1):
  if a[i]==a[i+1] and x!=i:
    j.append(a[i])
    x=i+1
  if len(j)>=2:
    break
j.append(0)
j.append(0)
print(j[0]*j[1])