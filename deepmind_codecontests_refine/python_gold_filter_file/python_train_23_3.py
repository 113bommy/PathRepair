n, k = map(int, input().split())
alice = []
bob = []
both = []
for _ in range(n):
    t, a, b = map(int, input().split())
    if a == 1 and b == 1:
        both.append((t, a, b))    
    elif a == 1 and b == 0:
        alice.append((t, a, b))
    elif a == 0 and b == 1:
        bob.append((t, a, b))
alice.sort()
bob.sort()
both.sort()
ans = 0
ca = 0
cb = 0
ia = 0
ib = 0
iboth = 0
#print(alice, bob, both)
while ca < k and cb < k and (ia < len(alice) and ib < len(bob) or iboth < len(both)):
    if iboth >= len(both) or ia < len(alice) and ib < len(bob) and alice[ia][0] + bob[ib][0] < both[iboth][0]:
        ans += alice[ia][0] + bob[ib][0]
        ia += 1
        ib += 1
    else:
        ans += both[iboth][0]
        iboth += 1
    ca += 1
    cb += 1
if cb >= k and ca >= k:
    print(ans)
else:
    print(-1)