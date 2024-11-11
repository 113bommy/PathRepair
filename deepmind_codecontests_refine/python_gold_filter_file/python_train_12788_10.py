a, b, c, d, e, f = map(int, input().split())

ans, cont = [0]*2, 0

for i in range(f//100+1):
    if i%a == 0 or i%b == 0:
        water = i*100
        x = min(f-water, i*e)

        suger = 0

        for j in range(x//c+1):
            s3 = j*c
            suger = max(suger, s3+((x-s3)//d)*d)

        if water != 0:
            if cont <= (100*suger) / (water+suger):
                ans = [water, suger]
                cont = (100*suger) / (water+suger)

print(sum(ans), ans[1])