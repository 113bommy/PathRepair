import collections
n = int(input())
a = [int(i) for i in input().split()]
l = collections.Counter(a)
l_ = [k for k, v in l.items() if v > 1]
if len(l_) > 1:
    l_.sort()
    if l[l_[-1]] > 3:
        print(l_[-1]**2)
    else:
        print(l_[-1]*l_[-2])
else:
    print(0)