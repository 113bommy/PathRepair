n,s = map(int,input().split())
ft = [list(map(int,input().split())) for i in range(n)]
maxi = s
for i in range(n):
  if maxi < ft[i][0]+ft[i][1]:
      maxi = ft[i][0]+ft[i][1]
print(maxi)
