import collections
import itertools


n = int(input())
c = collections.defaultdict(list)
for i, h in enumerate(map(int, str.split(input()))):

    c[h].append(i + 1)

s = tuple(map(c.get, sorted(c)))
sl = tuple(map(len, s))
if max(sl) > 2:

    i = sl.index(max(sl))
    print("YES")
    ps = itertools.permutations(s[i], sl[i])
    for perm in itertools.islice(itertools.permutations(s[i], sl[i]), 3):

        print(str.join(" ", map(str, itertools.chain.from_iterable(s[:i] + (perm,) + s[i + 1:]))))

elif sl.count(2) > 1:

    print("YES")
    print(str.join(" ", map(str, itertools.chain.from_iterable(s))))
    i = sl.index(2)
    print(str.join(" ", map(str, itertools.chain.from_iterable(s[:i] + (s[i][::-1],) + s[i + 1:]))))
    i = sl.index(2, i + 1)
    print(str.join(" ", map(str, itertools.chain.from_iterable(s[:i] + (s[i][::-1],) + s[i + 1:]))))

else:

    print("NO")
