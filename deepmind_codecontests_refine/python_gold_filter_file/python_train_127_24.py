t = int(input())
s = []
for i in range(t):
    n, m = map(int, input().split())
    a = input().split()
    b = input().split()
    if len(set(a) & set(b)) == 0:
        s.append(('NO',))
    else:
        l = list(set(a) & set(b))
        s.append(('YES', (1, l[0])))
for elem in s:
    if len(elem) == 1:
        print(elem[0])
    else:
        print(elem[0])
        print(*elem[1])
