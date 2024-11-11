n,w = map(int,input().split())
dpv = [10 ** 20 for i in range(10**5+1)]
dpv[0] = 0
for i in range(n):
  weight,value = map(int,input().split())
  for j in range(10**5-value,-1,-1):
    dpv[j+value] = min(dpv[j+value],dpv[j]+weight)
for i in range(10**5,-1,-1):
  if dpv[i] <= w:
    print(i)
    exit()