a,b=map(int,input().split())
n=0
while n*a-n+1<b:
  n+=1
print(n)