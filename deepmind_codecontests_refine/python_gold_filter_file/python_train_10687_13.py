n, k = map(int, input().split())
s = n
for i in range(k):
    if s % 10 == 0:
        s = s // 10
    else:
        s = s - 1
print(s)
