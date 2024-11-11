n, k = map(int, input().split())

a = list(map(int, input().split()))

rem = dict()

pow10 = [10**j for j in range(11)]

ans = 0

for ai in a:
    key = len(str(ai))
    if key not in rem:
        rem[key] = dict()
    if ai % k not in rem[key]:
        rem[key][ai % k] = 0
    rem[key][ai % k] += 1

for ai in a:
    for j in range(1, 11):
        if j in rem:
            key = (-(ai * pow10[j])) % k
            if key in rem[j]:
                ans += rem[j][key]

for ai in a:
    if int(str(ai) + str(ai)) % k == 0:
        ans -= 1

print(ans)
