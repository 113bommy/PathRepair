n = int(input())
ar = list(map(int, input().split()))

mod = lambda a,b: a%b if a%b!=0 else b
while 1:
    changed = False
    m = min(ar)
    for i in range(len(ar)):
        t = mod(ar[i], m)
        if t != ar[i]:
            changed = True
            ar[i] = t
    if not changed: break
print(sum(ar))
