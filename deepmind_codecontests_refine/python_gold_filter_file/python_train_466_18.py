t = list(map(int, input().split()))
ws = list(map(int, input().split()))
hs, hu = map(int, input().split())

res = 0

for (minu, wrongs, punt) in zip(t, ws, [500, 1000, 1500, 2000, 2500]):
    res += max(0.3 * punt, (1 - minu / 250) * punt - 50 * wrongs)
print(int(res + (hs * 100 + hu * -50)))