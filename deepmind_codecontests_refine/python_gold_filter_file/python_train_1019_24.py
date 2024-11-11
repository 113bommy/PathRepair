n=int(input());s=input()
b=0
w=s.count('.')
ans=w
for si in s:
  b+=(si=='#')
  w-=(si=='.')
  ans=min(ans,b+w)
print(ans)