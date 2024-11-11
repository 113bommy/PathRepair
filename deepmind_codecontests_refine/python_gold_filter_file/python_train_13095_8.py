from itertools import groupby
N = int(input())
S = input()
g = groupby(S)
print(len(list(g)))