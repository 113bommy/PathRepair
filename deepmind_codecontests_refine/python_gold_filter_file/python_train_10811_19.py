_=input()
s=input()
x=0
maxn=0
for i in s:
  if i == 'I':
    x+=1
  else:
    x-=1
  maxn=max(maxn,x)
print(maxn)