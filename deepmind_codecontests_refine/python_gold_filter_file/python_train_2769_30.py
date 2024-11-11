a, b = map(int, input().split())
temp = min(a, b)
res = 1
for i in range(1, temp+1):
    res = res * i;

print(res)