import re
n = int(input())

s = input()
l = 0
for x in re.findall(r'[x]{3,}', s):
    l += len(x)-2
    # print(x, l)
print(l)