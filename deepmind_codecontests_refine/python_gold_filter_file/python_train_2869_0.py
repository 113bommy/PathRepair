t = int(input())
for i in range(t):
    a = str(input())
    l = len(a)
    k = l - 2
    if l <= 10:
        print(a)
    else:
        print(a[0], end="")
        print(k, end="")
        print(a[l - 1])
    