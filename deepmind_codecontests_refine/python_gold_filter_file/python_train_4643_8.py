#import sys
#sys.stdin = open('in', 'r')
#n = int(input())
#a = [int(x) for x in input().split()]
#n,m = map(int, input().split())

s = input()
n = len(s)
mins=[ord('z')+1]*n

mins[-1] = s[-1]
for i in range(1, n):
    mins[-i-1] = min(mins[-i], s[-i-1])

a = []
r = ''
i = 0
j = 0
while i < n:
    while len(a) > 0 and a[-1] <= mins[i]:
        r += a.pop()
    mn = mins[i]
    while s[i] > mn:
        a.append(s[i])
        i += 1
    a.append(s[i])
    i += 1

while len(a) > 0:
    r += a.pop()
    
print(r)
