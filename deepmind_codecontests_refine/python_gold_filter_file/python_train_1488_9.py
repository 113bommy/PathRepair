from collections import defaultdict
 
R = lambda: map(int, input().split())
for _ in range(int(input())):
    n = int(input())
    num2idx = defaultdict(list)
    for i, num in enumerate(R()):
        num2idx[num].append(i)
    res = [3 * 10 ** 6] * (n + 1)
    for num, idxes in num2idx.items():
        mgap = max(idxes[0] + 1, n - idxes[-1])
        for i in range(1, len(idxes)):
            mgap = max(mgap, idxes[i] - idxes[i - 1])
        res[mgap] = min(res[mgap], num)
    cmin = res[0]
    for i in range(1, n + 1):
        cmin = min(cmin, res[i])
        print(cmin if cmin <= 3 * 10 ** 5 else -1, end=' ')
    print()