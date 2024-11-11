N=int(input())
n=N//4
for i in range(n+1):
  if (N-4*i)%7==0:
    print('Yes')
    exit()
print('No')