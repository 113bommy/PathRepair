n, m = map(int, input().split())
h = [int(i) for i in input().split(' ')]

h.sort(reverse=True)

pre_h = h[0]
ans = 0
cubes = 0
towers = 0

for i in range(0, n):
    if cubes + (pre_h - h[i])*towers < m:
        cubes += (pre_h - h[i])*towers
        towers += 1
        pre_h = h[i]
        if i == n-1 and cubes != 0:
            ans += 1
        continue
    cha = pre_h - h[i]
    cha -= (m - cubes)//towers
    ans += 1
    ans += cha // (m//towers)
    cubes = (cha - cha//(m//towers)*(m//towers)) * towers
    towers += 1
    pre_h = h[i]
    if i == n-1 and cubes != 0:
        ans += 1

print(ans)
