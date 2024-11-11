n = int(input())
lst = list(map(int, input().split()))

if sum(lst) != 0:
    print("YES\n1\n1 %d" % (n))
else:
    for i in range(1, n):
        if sum(lst[:i]) != 0:
            print("YES\n2\n1 %d\n%d %d" % (i, i+1, n))
            quit()
    print("NO")