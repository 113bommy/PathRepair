n, m = map(int, input().split(' '))
regions = [list() for i in range(m)]
for _ in range(n):
        name, region, score = input().split(' ')
        region, score = int(region), int(score)
        regions[region - 1].append((score, name))
for i in range(m):
        regions[i].sort()
for i in range(m):
        region = regions[i]
        if len(region) == 2 or region[-3][0] < region[-2][0]:
                print(region[-2][1] + ' ' + region[-1][1])
        else:
                print('?')

