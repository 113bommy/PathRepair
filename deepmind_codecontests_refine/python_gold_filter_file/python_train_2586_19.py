n=int(input())
a=[int(input()) for i in range(n)]
c,s=1,a[0]
while s!=2 and c<n:
  c+=1
  s=a[s-1]
print(c if c<n else -1)