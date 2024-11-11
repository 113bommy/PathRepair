N,X=map(int,input().split())
L=list(map(int,input().split()))

d=0
count=1
for l in L:
  d=d+l
  if X>=d:
    count +=1
print(count)
