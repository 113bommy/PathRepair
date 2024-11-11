n = int(input())
sher = str(input())
mor = str((input()))

sher = list(map(int, sher))
mor = list(map(int, mor))

sher = sorted(sher)
mor = sorted(mor)

sher1 = sher[:]
mor1 = mor[:]

k = 0

for i in range(n):

    if mor1[-1] >= sher1[-1]:
        mor1.pop(-1)
        sher1.pop(-1)
    else:
        k += 1
        mor1.pop(0)
        sher1.pop(-1)
print(k)

k = 0

for i in range(n):
    if mor[-1] > sher[-1]:
        k += 1
        mor.pop(-1)
        sher.pop(-1)
    else:
        mor.pop(0)
        sher.pop(-1)

print(k)
