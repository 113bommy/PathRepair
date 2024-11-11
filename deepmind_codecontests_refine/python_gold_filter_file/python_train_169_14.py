from sys import stdin, stdout
import collections
from collections import Counter

n = stdin.readline()
word = stdin.readline()

mylist = []
for i in range(1, len(word)):
    mylist.append(word[i - 1:i + 1])

a = Counter(mylist)
# print(type(a))
c=a.most_common(1)
b=dict(c)
# print(type(b))
for key in b:
    k=str(b.keys())
    # print(k)
    stdout.write(k[12:14])



