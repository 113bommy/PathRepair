n = int(input())
A = list(map(int,input().split()))

x = []
f = 0
for a in A:
    if a//400 < 8:
        x.append(a//400)
    else:
        f += 1
x = set(x)
l = len(x)
print(max(l,1),l+f)