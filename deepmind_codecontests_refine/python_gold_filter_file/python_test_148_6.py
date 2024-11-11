t = int(input())
while t:
    w, h = map(int, input().split())
    h1 = []
    h2 = []
    v1 = []
    v2 = []
    info1 = list(map(int, input().split()))
    info2 = list(map(int, input().split()))
    h1 = info1[1:]
    h2 = info2[1:]
    h1.sort()
    h2.sort()
    info1 = list(map(int, input().split()))
    info2 = list(map(int, input().split()))
    v1 = info1[1:]
    v2 = info2[1:]
    v1.sort()
    v2.sort()
    ans = max((h1[-1]-h1[0])*h, (h2[-1]-h2[0])*h, (v1[-1]-v1[0])*w, (v2[-1]-v2[0])*w)
    print(ans)
    t-=1