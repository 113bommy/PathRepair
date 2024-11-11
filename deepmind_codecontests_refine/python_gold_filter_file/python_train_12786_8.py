N=int(input())
for i in range(N//4+1):
  if (N-4*i)%7==0:
    print('Yes')
    exit()
print('No')