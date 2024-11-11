n=int(input())
s=input()

x=0
ans=0
for i in range(n):
  x=x+1 if s[i]=='I' else x-1
  ans=max(ans,x)
print(ans)