import sys
n = int(input())
s = [*map(int,sys.stdin.readline().split())]
 
su = sum(s)
ch = 0
a = []
for i in range(n):
    if (su-s[i])/(n-1)==s[i]:
        ch +=1
        a.append(i+1)
print(ch)
print(*a)

