from itertools import*
print(sum(len(list(j))//2 for _, j in groupby(open(0).read().split()[1:])))