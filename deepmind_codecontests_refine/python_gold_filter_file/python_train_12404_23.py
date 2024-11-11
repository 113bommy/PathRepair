n, m, r = map(int, input().split())

l = list(map(int, input().split()))
k = list(map(int, input().split()))

pri_min = min(l)

qut = r // pri_min
rem = r % pri_min
z = max(k)
#print(f"{pri_min} {qut} {rem} {z}")

if (z * qut)+rem >= r:
    print(z * qut+ rem)

else:
    print(r)
