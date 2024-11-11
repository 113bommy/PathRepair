n = int(input())
m = list(map(int,input().split()))
a = set(m)
if len(a) <= 2:
    print(0)
else:
    m.sort()
    if m.count(m[0])==1 and m.count(m[-1])==1:
        print(n-2)
    else:
        print(n-m.count(m[0])-m.count(m[-1]))