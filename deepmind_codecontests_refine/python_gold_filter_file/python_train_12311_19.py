t = int(input())
while t > 0:
    t -= 1
    l = list(map(int, input().split()))
    a = l[0]
    b = l[1]
    c = l[2]
    if a >= c:
        print('-1 '+str(b))
        continue
    if a * b <= c:
        print('1 -1')
        continue
    print('1 '+str(b))