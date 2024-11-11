N,H = map(int,input().split())
A = []
B = []
for i in range(N):
    a,b = map(int,input().split())
    A.append(a)
    B.append(b)
A.sort(reverse=True)
B.sort(reverse=True)
ans = 0

for b in B:
    if b>A[0] and H>0:
        H -= b
        ans += 1

if H > 0:
    ans += -(-H//A[0])

print(ans)