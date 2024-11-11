x = 6*int(input())
r = []

for m in range(1,10**7):
    d = m*(m+1)
    if d*m > x:
        break
    if x%d != 0:
        continue

    mx = x//d+m-1
    if mx%3 != 0:
        continue

    nx = mx//3
    if nx > m:
        r.append((m,nx))   
        r.append((nx,m))
    elif nx == m:
        r.append((m,nx))

print(len(r))
for sol in sorted(r):
    print(str(sol[0]) + " " + str(sol[1]))


