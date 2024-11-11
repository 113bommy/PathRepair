from itertools import groupby
n=int(input())
s=input()
print(len(list(groupby(s))))