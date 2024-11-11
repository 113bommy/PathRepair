from collections import defaultdict
# from itertools import groupby
def solve():
    freq_a = defaultdict(int)
    freq_b = defaultdict(int)

    n, m = list(map(int, input().split(" ")))
    arr_a = list(map(int, input().split(" ")))
    arr_b = list(map(int, input().split(" ")))

    for curr in arr_a:
        freq_a[curr] += 1

    for curr in arr_b:
        freq_b[curr] += 1

    amount = defaultdict(int)
    for key_a in freq_a:
        for key_b in freq_b:
            if freq_a[key_a] == freq_b[key_b]:
                delta = key_b - key_a if key_a <= key_b else m + key_b - key_a
                amount[delta] += freq_a[key_a]
    highest = m
    for i in amount:
        if amount[i] == n and i < highest:
            highest = i

    print(highest)
solve()