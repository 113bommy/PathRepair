n = int(input())
a = map(int, input().split())
a = list(a)
a.sort()
x = sum(a)
q = 0
if x % 2 == 0:
    print(x)
elif x % 2 != 0:
    for i in a:
        if i % 2 == 0:
            q = 0
        elif i % 2 != 0:
            q = i
            break
    print(x - q)
