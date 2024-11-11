import sys

inp = sys.stdin.readlines(); ii = 0

out = []

n, k = map(int, inp[ii].split())
ii += 1

probs = [int(z) for z in inp[ii].split()]
probs = []

for z in range(n):
    probs.append([int(inp[ii].split()[z]), z])
ii += 1

probsorted = sorted(probs, reverse=True)[:k]
total_profit = [sum(probsorted[r][0] for r in range(k))]
indexes = sorted([probsorted[r][1] for r in range(k)])

#
# for maxneeded in range(k):
#     maxindexes.append(probs.index(probsorted[maxneeded]))
#     del probsorted[-1]
#
# maxindexes.append(0)
#
# maxindexes.sort(reverse=True)

maxnums = probsorted[:k]

maxindexes = []
used = []

# for i in range(n):
#     if probs[i] in maxnums:
#         maxindexes.append(i)
#         maxnums.remove(probs[i])

res = []
# print(maxindexes)

if k == 1:
    out.append(str(probsorted[0][0]))
    out.append('\n')
    out.append(str(n))
else:

    for i in range(k - 1):
        if i == 0:
            res.append(str(indexes[i] + 1))
        else:
            res.append(str(indexes[i] - indexes[i - 1]))

    if len(indexes) >= 2:
        res.append(str(n - 1 - indexes[-2]))

    # if maxindexes[0] > 0:
    #     res.append(str(maxindexes[0] + 1))
    #     total_profit += probs[maxindexes[0]]
    #
    #     for x in range(2, k):
    #         res.append(str(maxindexes[x] - maxindexes[x-1]))
    #         total_profit += max(probs[maxindexes[x-1]: maxindexes[x]])
    # else:
    #     for x in range(1, k):
    #         res.append(str(maxindexes[x] - maxindexes[x - 1]))
    #         total_profit += max(probs[maxindexes[x - 1]: maxindexes[x]])
    #
    # res.append(str(n - maxindexes[-1]))
    # total_profit += probs[maxindexes[-1]]
    #
    out.append(str(total_profit[0]))
    out.append('\n')
    out.append(' '.join(res))

sys.stdout.write(''.join(out))


