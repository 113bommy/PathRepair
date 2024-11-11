n = int(input())
a = list(map(int, input().split()))

sm = a.copy()
for i in range (1, len(a)):
    sm[i] = sm[i-1] + a[i]

flag = False
index = -2
for i in range(0, len(a) - 1):
    if sm[i] != sm[len(a) -1] - sm[i]:
        flag = True
        index = i
        break


print(index + 1)
for i in range(index + 1):
    print(i + 1, end=' ')
