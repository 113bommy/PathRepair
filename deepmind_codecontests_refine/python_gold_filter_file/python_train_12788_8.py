A, B, C, D, E, F = map(int, input().split())
density = 0
for i in range(F//(100*A) +1):
    for j in range((F-100*A*i)//(100*B)+1):
        water = 100*A*i + 100*B*j
        if water == 0:
            continue
        for k in range((F-water)//C+1):
            for l in range((F-water-C*k)//D+1):
                sugar = C*k + D*l
                if density <= sugar/(sugar + water) and sugar <= (E/100)*water:
                    density = sugar/(sugar + water)
                    ans = [sugar+water, sugar]
print(ans[0], ans[1])