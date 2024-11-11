s=input()
from itertools import groupby as gb
print(len(list(gb(s)))-1)