inp = input().split()
n = int(inp[0])
k = int(inp[1])
a = input().rstrip().split()
b = input().rstrip().split()

z = a.count('0')
ok = True
if z == k:
    if k == 1:
        a = [b[0] if x=='0' else x for x in a]
        for (v,nxt) in zip(a,a[1:]):
            if int(v) >= int(nxt):
                break
        else:
            ok = False
else:
    ok = False

if ok:
    print("Yes")
else:
    print("No")
