A, B, C=map(int, input().split())
K=int(input())
i=0
while i<K:
  if B<=A:
    B*=2
  elif C<=B:
    C*=2
  i+=1
    
if A<B<C:
  print('Yes')
else:
  print('No')