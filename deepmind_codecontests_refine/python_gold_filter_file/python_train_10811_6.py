n=int(input())
s=input()
x=0
ma=0
for i in range(n):
  if(s[i]=="D"):
    x-=1
  else:
    x+=1
    ma=max([ma,x])
print(ma)