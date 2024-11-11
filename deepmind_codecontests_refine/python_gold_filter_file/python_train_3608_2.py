n=int(input())
l=list(map(int,input().split()))
s=sum(l)
c=0
for i in range(n):
  c=c+l[i]
  if c>=s/2.0:
    print(i+1)
    break