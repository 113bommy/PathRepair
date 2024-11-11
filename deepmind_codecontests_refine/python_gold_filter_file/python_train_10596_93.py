N, K = map(int, input().split())
b=0
while N>0:
  N=N//K
  b+=1
print(b)  