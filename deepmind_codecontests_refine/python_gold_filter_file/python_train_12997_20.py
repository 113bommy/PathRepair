import heapq
def main():
    N = int(input())
    A = list(map(int, input().split()))
    fl = [i for i in A[:N]]
    f = [sum(A[:N])]
    heapq.heapify(fl)
    ll = [-i for i in A[2*N:]]
    l = [sum(A[2*N:])]
    heapq.heapify(ll)
    for i in range(N):
        s = f[-1]
        if A[N+i] > fl[0]:
            s = s - fl[0] + A[N+i]
            heapq.heappushpop(fl, A[N+i])
        f.append(s)
        s = l[-1]
        if - A[2*N-1-i] > ll[0]:
            s = s + ll[0] + A[2*N-1-i]
            heapq.heappushpop(ll, -A[2*N-1-i])
        l.append(s)
    r = f[0] - l[-1]
    for i in range(N+1):
        r = max(r, f[i] - l[-1-i])
    return r
print(main())
