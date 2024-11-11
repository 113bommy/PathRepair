
n, t = [int(x) for x in input().split()]

r = -1
for i in range(10**(n-1), (10**n)):
    if i % t == 0:
        r = i
        break

print(r)


