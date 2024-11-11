import sys
input = lambda : sys.stdin.readline().strip()
t = int(input())
while t:
    t-=1
    n = int(input())
    if n<=3:
        print(-1)
        continue
    ans = []
    for i in range(1,n+1,2):
        ans.append(i)
    ans = ans[::-1]
    ans.append(4)
    ans.append(2)
    for i in range(6,n+1,2):
        ans.append(i)
    print(' '.join(map(str,ans)))