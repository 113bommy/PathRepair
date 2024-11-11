n = int(input())
for i in range(n):
    w, h = map(int,input().split())
    xyn = list(map(int, input().split()))[1:]
    xym = list(map(int, input().split()))[1:]
    xny = list(map(int, input().split()))[1:]
    xmy = list(map(int, input().split()))[1:]
    xynm = max(xyn)-min(xyn)
    xymm = max(xym)-min(xym)
    xnym = max(xny)-min(xny)
    xmym = max(xmy)-min(xmy)
    if max(xynm,xymm)*h > max(xnym,xmym)*w:
        print(max(xynm,xymm)*h)
    else:
        print(max(xnym,xmym)*w)