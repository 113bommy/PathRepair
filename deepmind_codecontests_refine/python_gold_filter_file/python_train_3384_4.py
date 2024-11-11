n = int(input())
a = list(map(int, input().split()))
r, b, c = 0, [a[0]], 0
for x, y, z in zip(a, a[1:], a[2:]):
    if x != y != z:
        c += 1
    else:
        if c & 1:
            b.extend([y]*(c+1))
        else:    
            b.extend([1-y]*(c//2) + [y]*(c//2+1))
        r = max(r, (c+1)//2)
        c = 0
y = a[-1]            
if c & 1:
    b.extend([y]*(c+1))
else:    
    b.extend([1-y]*(c//2) + [y]*(c//2+1))
r = max(r, (c+1)//2)

print(r)
print(*b)
