import sys
from collections import defaultdict
#def input(): return sys.stdin.readline()

H = defaultdict(lambda: 0) 
for _ in range(int(input())):
    s = input()
    stack = []
    for i in s:
        if not stack:
            stack.append(i)
            continue
        if stack[-1] == '(' and i == ')':
            stack.pop()
            continue
        stack.append(i)
    l = stack.count('(')
    r =len(stack) - l
    if l*r:
        continue
    H[(1-2*(l == 0))*(l+r)] += 1
dans = (H[0]//2)*2
H[0] = 0 
for j in H.copy().keys():
    dans += min(H[j], H[-j])
print(dans//2)
