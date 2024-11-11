n=int(input())
s=input()
p=1
for i in range(0,n-1):
  if s[i]!=s[i+1]:
    p+=1
print(p)