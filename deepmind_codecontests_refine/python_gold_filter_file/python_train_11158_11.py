import sys, math
input = sys.stdin.readline
 
def getInt(): return int(input())
def getVars(): return map(int, input().split())
def getList(): return list(map(int, input().split()))
def getStr(): return input().strip()
## -------------------------------

n = getInt()
s = getStr()
t = getStr()

d = {}
d['aaaa'] = ['ab', 'c', '']
d['aaab'] = ['ac', 'b', '']
d['aaac'] = ['ab', 'c', '']
d['aaba'] = ['ac', 'b', '']
d['aabb'] = ['ab', 'c', '']
d['aabc'] = ['ac', 'b', '']
d['aaca'] = ['ab', 'c', '']
d['aacb'] = ['ab', 'c', '']
d['aacc'] = ['ac', 'b', '']

d['abab'] = ['a', 'c', 'b']
d['abac'] = ['b', 'c', 'a']
d['abba'] = ['a', 'c', 'b']
d['abbb'] = ['bc', 'a', '']
d['abbc'] = ['b', 'a', 'c']
d['abca'] = ['b', 'a', 'c']
d['abcb'] = ['b', 'a', 'c']
d['abcc'] = ['ac', 'b', '']

d['acac'] = ['a', 'b', 'c']
d['acba'] = ['b', 'c', 'a']
d['acbb'] = ['c', 'ab', '']
d['acbc'] = ['c', 'a', 'b']
d['acca'] = ['a', 'b', 'c']
d['accb'] = ['c', 'a', 'b']
d['accc'] = ['bc', 'a', '']

d['baba'] = ['a', 'c', 'b']
d['babb'] = ['a', 'bc', '']
d['babc'] = ['a', 'c', 'b']
d['baca'] = ['a', 'b', 'c']
d['bacb'] = ['a', 'b', 'c']
d['bacc'] = ['bc', 'a', '']

d['bbbb'] = ['ab', 'c', '']
d['bbbc'] = ['ba', 'c', '']
d['bbca'] = ['ab', 'c', '']
d['bbcb'] = ['ab', 'c', '']
d['bbcc'] = ['ab', 'c', '']

d['bcbc'] = ['a', 'c', 'b']
d['bcca'] = ['c', 'b', 'a']
d['bccb'] = ['b', 'a', 'c']
d['bccc'] = ['b', 'ac', '']

d['caca'] = ['a', 'b', 'c']
d['cacb'] = ['a', 'b', 'c']
d['cacc'] = ['cb', 'a', '']

d['cbcb'] = ['a', 'b', 'c']
d['cbcc'] = ['b', 'ac', '']

d['cccc'] = ['ac', 'b']


res = ''
if t < s:
    s,t = t, s
for s1 in d[s+t]:
    if s1 != '':
        res += s1*n
print('YES')
print(res)
