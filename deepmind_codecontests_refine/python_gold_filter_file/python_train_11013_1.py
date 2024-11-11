n,k,q=map(int,input().split())
ans=[-q]*n
for i in range(q):
  a=int(input())
  ans[a-1]+=1
  
for i in range(n):
  print('Yes' if ans[i] > -k else 'No')

  