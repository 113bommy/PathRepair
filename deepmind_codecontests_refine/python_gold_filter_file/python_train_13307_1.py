from itertools import*
N,*S=open(0)
print(sum(a*b*c for a,b,c in combinations([sum(1 for s in S if s[0]==c) for c in "MARCH"],3)))