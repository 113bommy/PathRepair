p = { 0: 4, 1: 1, 2: 3, 3: 2, 4: 0, 5: 5 }
n = int(input())
res = 0
for i in range(6):
    if (n & (1 << i)):
        res |= (1 << p[i])
print(res)