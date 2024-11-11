a,b,c,d=map(int,input().split())
s='Yes'
if abs(a-c)>d:
  if abs(a-b)>d or abs(b-c)>d:
    s='No'
print(s)