n, m = [int(x) for x in input().split()]
a = [input() for i in range(n)]
k = 0
while (True):
    if n%2: break
    br = False
    for i in range(n//2):
        if a[i] != a[n-i-1]:
            br = True
            break
    if br: break
    k += 1
    n //= 2
print(n)