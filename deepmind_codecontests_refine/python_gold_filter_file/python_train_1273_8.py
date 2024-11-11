import bisect

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

c = [0] * n
index = 0
for i, j in zip(a, b):
    c[index] = i - j
    index += 1

d = sorted(c)
# print(d)
ans = 0
for i in range(n):
    if d[i] <= 0:
        # print(d[i])
        if d[i] == 0:
            x = bisect.bisect_left(d, 1)
        else:
            x = bisect.bisect_left(d, abs(d[i])+1)

        index = x + 1
        ans += n - index + 1
        # print(ans)
    else:
        index = i + 1
        ans += n - index
print(ans)
