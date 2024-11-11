import itertools as i
_,S=open(0)
print(len(list(i.groupby(S)))-1)