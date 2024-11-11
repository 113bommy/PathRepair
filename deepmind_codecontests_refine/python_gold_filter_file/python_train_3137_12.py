n = int(input())
for i in range(n):
    a = list(input())
    if len(set(a)) == 1:
        print(-1)
        continue
    if a == list(reversed(a)):
        a = a[1:] + [a[0]]
    print(*a, sep='')