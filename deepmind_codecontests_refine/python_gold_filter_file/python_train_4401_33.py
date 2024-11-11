t = int(input())
while t:
    n = int(input())
    a = list(map(int, input().split()))
    s = set(a)
    l1 = len(a)
    l2 = len(s)
    if l2 == 1:
        print(n)
    else:
        print(1)
    t -=1