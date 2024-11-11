n, k, p, x, y = map(int, input().split())
l1 = list(map(int, input().split()))
i = l2 = l3 = 0
l1.sort()
while i < k and l1[i] < y:
    i+=1
if i == n:
    l2 = l1 + [y]*(n-k)
    l3 = [0] * k + [1]*(n-k)
else: 
    l2 = l1[0:i] + [y] * (n - k) + l1[i:]
    l3 = [0] * i + [1] * (n-k) + (k-i)*[0]
z = sum(l2)
k = (n+1)//2 - 1
if z > x:
    j = 0
    while j < k:
        if l3[j] == 1:
            m = l2[j]
            if l2[j] - (z-x) > 0:
                l2[j] -= (z-x)
            else:
                l2[j] = 1
            z -= m - l2[j]
        if z < x:
            break
        j += 1
    if z > x:
        print(-1)
    else:
        for i in range(n):
            if l3[i] == 1:
                print(l2[i], end=' ')
elif l2[k] < y:
    print(-1)
else:
    for i in range(n):
        if l3[i] == 1:
            print(l2[i], end=' ')
