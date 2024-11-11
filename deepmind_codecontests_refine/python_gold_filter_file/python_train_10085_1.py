import re
print(*[x for x in re.split(r'\s|"|,|\.',input())if 2<len(x)<7])
