A, B, C, D, E, F = map(int, input().split())
ans = [100*A, 0]
for a in range(0, F+1, A*100):
    for b in range(0, F+1, B*100):
        for c in range(0, F+1, C):
            for d in range(0, F+1, D):
                water = a+b
                sugar = c+d
                if water+sugar > F or water == 0 or 100*sugar > water*E:
                    break
                else:
                    if ans[1]/(ans[0]+ans[1]) < sugar/(water+sugar):
                        ans = [water, sugar]

print(ans[0]+ans[1], ans[1])
