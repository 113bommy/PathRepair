n,m=map(int,input().split())
l=[list(map(int,input().split())) for _ in range(m)]
l.sort(key=lambda x : x[1])
a=0
b=0
for x in l:
  if x[0]>=b:
    b=x[1]
    a+=1
print(a)
