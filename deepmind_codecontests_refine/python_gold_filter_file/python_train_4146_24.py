import bisect
 
n = int(input())
a = list(map(int, input().split()))
a.sort()
 
res = 0
for i in range(n - 1 , -1, -1):
    if a[i] == int(a[i]):#判定
        b = 1
        while b <= a[i]:
            b =b*2
 
        j = bisect.bisect_left(a, b - a[i])
        if i > j:
            if b - a[i] == a[j]:
                res += 1
                a[j] = a[j] - 0.5
                a[i] = a[i] + 0.5
print(res)