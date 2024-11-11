n = int(input())
s = input()
a = s.count('R')
if a > n-a:
    print('Yes')
else:
    print('No')