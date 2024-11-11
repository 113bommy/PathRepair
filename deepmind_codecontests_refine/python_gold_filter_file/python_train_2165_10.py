n=int(input())
a=map(int,input().split())
i=1
for k in a:
  if k==i: i+=1
print(n-i+1 if i>1 else -1)
