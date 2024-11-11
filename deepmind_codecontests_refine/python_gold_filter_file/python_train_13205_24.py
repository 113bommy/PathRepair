# python3 (3.4.3)
import sys
input = sys.stdin.readline

# main
N,A,B = map(int,input().split())
V = list(map(int,input().split()))

V.sort(reverse=True)

ans1 = sum(V[:A])/A

ans2 = 1
cnt = V.count(V[0])
if cnt > A:
    ans2 = 0
    for i in range(A,min(B,cnt)+1):
        tmp = 1
        for j in range(i):
            tmp *= cnt-j
            tmp //= j+1
        ans2 += tmp
else:
    cnt1 = V.count(V[A-1])
    cnt2 = V[:A].count(V[A-1])
    if cnt1 > 1:
        for i in range(cnt2):
            ans2 *= cnt1-i
            ans2 //= i+1

print(ans1)
print(ans2)