a=input()
b=input()
ans=0
for i,j in zip(a,b):
  if i != j:
    ans+=1
print(ans)
