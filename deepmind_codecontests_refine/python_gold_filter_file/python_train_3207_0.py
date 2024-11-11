from math import ceil
import re
S = input()
N = len(S)

X = re.findall('R+L+', S)
ans = [0] * N

i = 0
for x in X:
    x_len = len(x)
    start = x.find('RL')

    ans[i + start] += (x_len - start - 1) // 2 + ceil((start + 1) / 2)
    ans[i + start + 1] += (start + 1) // 2 + ceil((x_len - start - 1) / 2)

    i += x_len

print(*ans, sep=' ')
