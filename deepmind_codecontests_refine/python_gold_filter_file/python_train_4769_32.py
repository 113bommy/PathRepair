from heapq import heappush, heappop
N = int(input())
s = list(map(int,input().split()))
a, b = s[1], s[2]
L = []
R = []
heappush(L,-a)
heappush(R,a)

bsum = b
t = 0
for k in range(N-1):
    s = input()
    if s[0] == "1":
        s = list(map(int,s.split()))
        a = s[1]
        b = s[2]
        bsum += b
        if -L[0] <= a <= R[0]:
            pass
        else:
            t += min(abs(a+L[0]),abs(a-R[0]))
        heappush(L,-a)
        heappush(R,a)
        if -L[0] > R[0]:
            c = heappop(L)
            d = heappop(R)
            heappush(R,-c)
            heappush(L,-d)
    else:
        print(-L[0], t+bsum)