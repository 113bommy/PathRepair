n,m=map(int,input().strip().split(' '))
mini=10**9
for i in range(n):
  a,b=map(int,input().strip().split(' '))
  s=a/b
  if s<mini:
    mini=s

print(mini*m)