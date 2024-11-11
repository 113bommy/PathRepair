n = input()
ec = [0] * 3
maxi, maxv = 0, 0
for i, v in enumerate(map(int, input().split())):
    i %= 3
    ec[i] += v
    if ec[i] > maxv:
        maxi = i
        maxv = ec[i]
print(('chest', 'biceps', 'back')[maxi])