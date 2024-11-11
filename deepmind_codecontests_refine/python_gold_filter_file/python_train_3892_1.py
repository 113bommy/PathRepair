from collections import defaultdict as dc
def mlt(): return map(int, input().split())
def arp(): return [*mlt()]


s = input()
mp = dc(lambda: 0)
for n in s:
    mp[ord(n)-97] += 1
cntr = 0
for n in s:
    if mp[ord(n)-97] % 2:
        cntr += 1

if cntr <= 1:
    print('First')
else:
    s1 = ['Second', 'First']
    print(s1[len(s) % 2])
