k=int(input())
a,b=map(int,input().split())
n=1
while k*n<=b:
  n+=1
print('OK' if a<=(n-1)*k<=b else 'NG')