import sys
from itertools import permutations


def perebor(s, stroka):
    count = 0
    s2 = list(s)
    for l in range(len(stroka)):
        if s2[l] != stroka[l]:
            count += 1
            s2[l] = stroka[l]

    for ind in range(len(stroka), len(s)):
        if s2[ind] != s2[ind - 3]:
            s2[ind] = s2[ind - 3]
            count += 1
    return s2, count


n = int(input())
s = list(input())
count = 0
if n < 3:
    if n == 1:
        print(0)
        print(''.join(s))
        sys.exit(0)
    else:
        p = []
        pos = ['RG', 'GR', 'RB', 'BR', 'GB', 'BG']
        for pa in pos:
            p = p + list(permutations(pa))
else:
    p = permutations('RGB')

count_best = 9999999
s_best = 99999999
for l in p:
    s1, count1 = perebor(s, l)
    if count1 < count_best:
        s_best = s1
        count_best = count1
print(count_best)
print(''.join(s_best))
