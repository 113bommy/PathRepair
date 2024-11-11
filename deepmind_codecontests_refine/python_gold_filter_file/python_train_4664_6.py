n,m = map(int,input().split())
lis = [0]*205
lis[0] = 300000
lis[1] = 200000
lis[2] = 100000
if n == m and n == 1:
  print(1000000)
else:
  print(lis[n-1]+lis[m-1])
