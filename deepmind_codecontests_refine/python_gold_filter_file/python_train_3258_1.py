t=int(input())
for i in range(t):
  n,m=map(int,input().split())
  l1=list(map(int,input().split()))
  l2=list(map(int,input().split()))
  l1.sort(reverse=True)
  sum1=0
  for j in range(n):
    if j<m and l1[j]>=j+1:
     sum1=sum1+l2[j]
    else:
      sum1=sum1+l2[l1[j]-1] 
    # print(sum1)  
  print(sum1)  