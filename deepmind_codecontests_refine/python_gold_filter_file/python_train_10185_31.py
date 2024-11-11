a=int(input())
b=int(input())
c=int(input())
n=int(input())
ans=0
for i in range(a+1):
  for j in range(b+1):
    for h in range(c+1):
      if 500*i+100*j+50*h==n:
        ans+=1
print(ans)