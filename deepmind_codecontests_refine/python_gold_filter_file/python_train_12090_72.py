t = 0
range_arr = []


def read_input():
    global t, range_arr

    t = int(input())

    range_arr = [[0, 0] for i in range(t)]

    for i in range(t):
        range_arr[i][0], range_arr[i][1] = map(int, input().split())


def solve():
    pairs = []

    for r in range_arr:
        pair = []

        for i in range(r[0], r[1] + 1):
            if i == 1:
                pair = [1, r[1]]
                pairs.append(pair)
                break

            if (i * 2) in range((i * 2), r[1] + 1):
                pair = [i, (i * 2)]
                pairs.append(pair)
                break

    return pairs


read_input()

pairs = solve()

for pair in pairs:
    print(pair[0], pair[1])
