days = list(map(int, input().split()))
dub = []
sum = 0
for i in range(days[0]):
    a = list(map(int, input().split()))
    sum += min(a)
    dub.append(min([a[0]*2, a[1]]) - min(a))
dub.sort()
for i in range(days[0]-1, days[0]-days[1]-1, -1):
    sum += dub[i]

print(sum)
