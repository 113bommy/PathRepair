def xorinacci(n, a, b):
    if n % 3 == 0:
        return a
    elif n % 3 == 1:
        return b
    else:
         return a^b


q = int(input())
for i in range(q):
    a, b, n = map(int, input().split())
    print(xorinacci(n, a, b))
