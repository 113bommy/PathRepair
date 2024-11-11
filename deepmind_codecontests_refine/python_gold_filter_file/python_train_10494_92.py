n,a,b,c,d=map(int,input().split())
s=input()
x='Yes'
if '##' in s[a-1:c]:
  x='No'
elif '##' in s[b-1:d]:
  x='No'
elif c>d:
  if '...' not in s[b-2:d+1]:
    x='No'  
print(x)