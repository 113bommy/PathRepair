n, s = [int(x) for x in input().split()]
a = sorted([int(x) for x in input().split()])
if sum(a)-a[-1]>s:
    print("NO")
else:
    print("YES")