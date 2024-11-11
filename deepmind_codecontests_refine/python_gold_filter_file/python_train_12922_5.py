n = int(input())
l = list(map(int,input().split()))
mx = max(l)
mn = min(l)
#print(l.count(mx),l.count(mn))
if l.count(mx)>=2:
    l.remove(mn)
    print(max(l) - min(l))
elif l.count(mn)>=2:
    l.remove(mx)
    print(max(l) - min(l))
else:
    wo_max = list(filter(lambda a: a != mx, l))
    x = max(wo_max) - min(wo_max)
    wo_min = list(filter(lambda a: a != mn, l))
    y = max(wo_min) - min(wo_min)
    if x>y:
        print(y)
    else:
        print(x)
