from sys import stdin
from collections import Counter
from itertools import zip_longest

def rplc(text,index=0,replacement=''):
    return '%s%s%s'%(text[:index],replacement,text[index+1:])


n = stdin.readline()
n = int(n)
s = stdin.readline()
s = s.rstrip('\n')

#n = 300000
#s = '2' * n

s = list(s)
per_c = n // 3
cnt = Counter(s)


def replace_left_2_right(old, new):
    global s
    global cnt
    for i, c in enumerate(s):
        if cnt[new] >= per_c:
            break
        if c == old and cnt[old] > per_c and cnt[new] < per_c:
            #s = rplc(s, i, new)
            s[i] = new
            cnt[new] += 1
            cnt[old] -= 1

def replace_right_2_left(old, new):
    global s
    global cnt
    for j in range(n):
        i = n - j - 1
        c = s[i]
        if cnt[new] >= per_c:
            break
        if c == old and cnt[old] > per_c and cnt[new] < per_c:
            #s = rplc(s, i, new)
            s[i] = new
            cnt[new] += 1
            cnt[old] -= 1

a = '2'
for b in ['0', '1']:
    replace_left_2_right(a, b)

a = '0'
for b in ['2', '1']:
    replace_right_2_left(a, b)

replace_right_2_left('1', '2')
replace_left_2_right('1', '0')


print("".join(s))
