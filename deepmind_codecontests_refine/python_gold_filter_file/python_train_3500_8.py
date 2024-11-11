a,b = map(int, input().split())
if b == 1:
    print(min(map(int, input().split())))
elif b == 2:
    l = list(map(int, input().split()))
    print(max(l[0], l[-1]))
else:
    print(max(map(int, input().split())))