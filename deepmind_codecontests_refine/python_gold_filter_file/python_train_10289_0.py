from string import*
from itertools import*
b = ascii_lowercase
s = input()
if len(s) < 26:
    print(s + sorted(set(b) - set(s))[0])
else:
    d = -[p*len(list(k)) for p, k in groupby([i < j for i, j in zip(s[-1::-1], s[-2::-1])])][0] - 2
    print(-(d < -26) or s[:d] + sorted(set(s[d+1:]) - set(b[:ord(s[d]) - 97]))[0])