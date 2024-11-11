a=int(input())
b=int(input())
c=int(input())
q=int(input())
ans=0
for i in range(a+1):
  for k in range(b+1):
    for p in range(c+1):
      if 500*i+100*k+50*p==q:
        ans+=1
print(ans)
