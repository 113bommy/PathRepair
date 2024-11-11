n = int(input())
a = list(map(int, input().split()))
res = 0
num = 0
for i in range(2, len(a), 1):
    if a[i] == a[i - 1] + a[i - 2]:
        num += 1
    else:
        num = 0 

    if num > res:
        res = num 

print(min(res + 2, n))