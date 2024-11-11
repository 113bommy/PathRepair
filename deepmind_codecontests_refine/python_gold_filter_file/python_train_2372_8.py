n=int(input())
s=input()
r=s.count('R')
g=s.count('G')
b=s.count('B')
ans=r*g*b
for i in range(1,(n+1)//2):
  for j in range(n-2*i):
    if len(set([s[j],s[j+i],s[j+2*i]]))==3:
      ans-=1
print(ans)