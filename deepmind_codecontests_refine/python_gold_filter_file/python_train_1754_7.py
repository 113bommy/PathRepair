N,a,b,c,d=map(int, input().split())
N-=1
a,b=0,abs(b-a)
#上下をn回とすると、0<=n<=N//2
if d*N<b:
  print('NO')
  exit()
  
for i in range(N//2+1):
  e=b-(N-i*2)*d
  f=b-(N-i*2)*c
  if e<=(d-c)*i and (c-d)*i<=f:
    print('YES')
    exit()
print('NO')