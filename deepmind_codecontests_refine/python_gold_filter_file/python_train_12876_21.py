from collections import Counter

input()
l = list(filter(lambda x: x != 0, map(int, input().split())))
print(len(Counter(l)))
