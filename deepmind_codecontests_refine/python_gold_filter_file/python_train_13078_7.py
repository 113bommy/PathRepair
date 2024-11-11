
n = int(input())
a = list(map(int, input().split()))

if n == 1:
    print(360)
    exit(0)

r = 360
for i in range(len(a)):
    for j in range(1, len(a)+1):
        k = (i + j) % n
        if i == k:
            s1 = sum(a)
        elif i < k:
            s1 = sum(a[i:k])
        else:
            s1 = sum(a[k:i])
        ss = abs((360 - s1) - s1)
        if ss < r:
            r = ss

print(r)
