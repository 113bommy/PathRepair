n = int(input())
a = [int(x) for x in input().split()]
s = sum(a)
if n == 1 or (len(set(a)) == 1 and n == 2):
    print(-1)
else:
    add = 0
    l = []
    for i in range(n - 1):
        l.append(i + 1)
        add += a[i]
        if 2 * add != s:
            break
    print(len(l))
    for i in l:
        print(i, end = " ")
    print()