a,b,c=map(int,input().split())
flag=False
for i in range(b):
  if a*i%b==c:
    flag=True
print(['NO','YES'][flag])