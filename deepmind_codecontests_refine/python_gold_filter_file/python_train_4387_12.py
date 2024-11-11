s=input()
h=list(map(str,input().split()))
c=0
for i in range(5):
  if s[0] in h[i]:
    c=c+1
  if s[1] in h[i]:
    c=c+1
if c>0:
  print('YES')
else:
  print('NO')