n, m, k = input().split()
n = int(n)
m = int(m)
k = int(k)
module = 1000000007
if k <= 0:
    print(0)
elif k == 1 or k > n:
    print((m ** n) % module)
elif k == n:
    print((m ** int((n + 1) / 2)) % module)
elif k % 2 == 1:
    print((m ** 2) % module)
elif k % 2 == 0:
    print(m % module)