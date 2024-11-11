a,b = map(int, input().split())
tmp = min(a,b)
res = 1
for i in range(1,tmp+1):
    res = res * i
print(res)