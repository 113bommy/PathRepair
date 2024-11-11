A,B,C,X = map(int, open(0).read().split())

ans = 0

for a in range(A+1):
    for b in range(B+1):
        for c in range(C+1):
            ans += (a*500+b*100+c*50 == X)

print(ans)