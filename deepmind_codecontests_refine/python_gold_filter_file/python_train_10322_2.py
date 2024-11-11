import sys
n = input()
a = list(map(int, sys.stdin.readline().split(' ')))
t=a[-1]
ans=len(a)
for i in range(-2,-len(a)-1,-1):
    if a[i]==t:
        continue
    else:
        ans = len(a)+i+1
        break
print(ans)