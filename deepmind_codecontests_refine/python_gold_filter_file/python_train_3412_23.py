K=int(input())
num=7
for i in range(1000000):
  modnum=num%K
  if modnum==0:
    print(i+1)
    exit()
  num=modnum*10+7
print(-1)