#574_B

ln = [int(i) for i in input().split(" ")]
n = ln[0]
k = ln[1]

s = 0
i = 0

ans = -1

while s < 10 ** 10:
    i += 1
    s += i
    if (i + s) / 2 == (n + k) / 2:
        ans = s - k
        break

print(ans)
