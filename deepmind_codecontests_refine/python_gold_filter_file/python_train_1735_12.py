from collections import defaultdict


def possible(start, Dict, n, lis):
    if len(lis) == n:
        print(*lis)
        return lis
    if start % 3 == 0 and Dict[start//3]:
        ans1 = possible(start//3, Dict, n, lis+[start//3])
    elif Dict[start*2] > 0:
        ans2 = possible(start*2, Dict, n, lis+[start*2])


n = int(input())

arr = [int(i) for i in input().split()]
Dict = defaultdict(int)
for i in arr:
    Dict[i] += 1
for star in arr:
    possible(star, Dict, n, [star])

