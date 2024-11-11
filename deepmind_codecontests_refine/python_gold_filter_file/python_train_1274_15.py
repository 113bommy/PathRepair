from sys import stdin,stdout
for query in range(int(stdin.readline())):
  n=int(stdin.readline())
  a=[int(x) for x in stdin.readline().split()]
  b=a[0]>0
  changes=[]
  for x in range(n):
    d=a[x]>0
    e=b
    if d != e:
      b=not b
      changes.append(x)
  if len(changes)>0:
    total=max(a[:changes[0]])
    y=len(changes)
    for x in range(y):
      if x==y-1:
        total+=max(a[changes[x]:])
      else:
        total+=max(a[changes[x]:changes[x+1]])
    stdout.write(str(total)+'\n')
  else:
    stdout.write(str(max(a))+'\n')