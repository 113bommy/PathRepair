n = int(input())
otr = [tuple(map(int, input().split())) for i in range(n)]

left = sorted(otr, key=lambda x: (x[0], -x[1]))

for i, el in enumerate(left[1:]):
    one, two = left[i], el

    if one[0] == two[0] or one[1] >= two[1]:
        print(f'{otr.index(two) + 1} {n - otr[::-1].index(one)}')
        exit()

print(-1, -1)