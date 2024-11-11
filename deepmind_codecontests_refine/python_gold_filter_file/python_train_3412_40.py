a=int(input())
b=7
for i in range(a):
  if b%a==0:
    print(i+1)
    break
  b=10*b%a+7
  if i==a-1:
    print(-1)
    break