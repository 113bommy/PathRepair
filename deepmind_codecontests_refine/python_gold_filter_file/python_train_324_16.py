int(input())

a = map(int, input().split())

o, e = [], []

for aa in a:
    if aa%2==0:
        o.append(aa)
    else:
        e.append(aa)

if abs(len(o) - len(e)) < 2:
    print(0)
elif len(o) > len(e):
    o.sort(reverse=True)
    print(sum(o[len(e)+1:]))

else:
    e.sort(reverse=True)
    print(sum(e[len(o)+1:]))

