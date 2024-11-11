n = int(input())
for i in range(n):
    h = int(input())
    b = set()
    l = list(map(int,input().split()))[:h]
    for l,v in enumerate(l):
        b.add(((v)%h+l)%h)
    if len(b)==h:
        print("YES")
    else:
        print("NO")
        