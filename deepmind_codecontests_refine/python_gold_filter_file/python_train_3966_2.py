import math
n,m = map(int, input().strip().split(' '))
#n=int(input())
#lst = list(map(int, input().strip().split(' ')))
for i in range(m):
    l,r = map(int, input().strip().split(' '))
s='10'*n
print(s[:n])