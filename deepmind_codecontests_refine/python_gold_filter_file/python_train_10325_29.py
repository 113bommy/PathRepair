n = int(input())
l = list(map(int,input().split()))
l.sort()
su = sum(l)
tm = sum(l[:n-1])
if su % 2 == 0 and tm >= l[n-1]:
    print("YES")
else:
    print("NO")