from itertools import groupby
N = int(input())
S = input()
G = groupby(S)
print(len(list(G)))