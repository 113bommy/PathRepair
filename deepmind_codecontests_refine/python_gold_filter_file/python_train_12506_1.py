q = int(input())
a = [input() for i in range(2 * q)]

for i in range(q):
    n = int(a[2 * i])
    s = a[2 * i + 1]
    if n >= 3:
        print("YES")
        print(2)
        print(s[0], end=' ')
        for j in range(1, n):
            print(s[j], end='')
        print()
    else:
        if int(s[0]) < int(s[1]):
            print("YES")
            print(2)
            print(s[0], s[1])
        else:
            print("NO")
