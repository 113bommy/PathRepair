n=int(input())
s=input()
m=n
for i in range(0,n-1):
  if s[i]==s[i+1]:
    m-=1
print(m)