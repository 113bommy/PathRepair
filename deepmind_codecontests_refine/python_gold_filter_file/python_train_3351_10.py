q = int(input())
for i in range(q):
    s = set(input())
    t = set(input())
    if s & t:
        print("YES")
    else:
        print("NO")