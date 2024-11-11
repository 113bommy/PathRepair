n = int(input())
s = input()
r = s.count('R')
if r > n - r:
    print('Yes')
else:
    print('No')