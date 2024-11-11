n = int(input())

arr = list(map(int, input().split()))

p = 0
s = 0

while p + 1 <= n:
    p += 1
    m = arr[p - 1]
    while p <= m:
        m = max(m, arr[p - 1])
        p += 1
    p -= 1
    s += 1
    #print(p)
print(s)
