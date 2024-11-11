def multiple_input(): return map(int, input().split())


def list_input(): return list(map(int, input().split()))


big = int(1e15)
n = int(input())
a = list_input()
a.sort()
flag = 0
m = big
for i in range(1, big):
    s = 0
    for j in range(n):
        if pow(i, j) > big:
            flag = 1
            break
        s += abs(a[j] - pow(i, j))
    if s > m or flag == 1:
        break
    m = min(m, s)

print(m)
