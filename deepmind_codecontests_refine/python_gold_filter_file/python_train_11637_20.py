from itertools import groupby

n = int(input())
aaa = list(map(int, input().split()))
bbb = list(map(int, input().split()))

idx_a = {}
cnt_a = {}
i = 0
for a, itr in groupby(aaa):
    cnt = len(list(itr))
    i += cnt
    idx_a[a] = i
    cnt_a[a] = cnt

idx_b = {}
cnt_b = {}
i = 0
for b, itr in groupby(bbb):
    cnt = len(list(itr))
    idx_b[b] = i
    cnt_b[b] = cnt
    i += cnt

slide = 0
for a in idx_a:
    if a not in idx_b:
        continue
    if cnt_a[a] + cnt_b[a] > n:
        print('No')
        exit()
    slide = max(slide, idx_a[a] - idx_b[a])

print('Yes')
if slide > 0:
    bbb = bbb[-slide:] + bbb[:-slide]
print(*bbb)
