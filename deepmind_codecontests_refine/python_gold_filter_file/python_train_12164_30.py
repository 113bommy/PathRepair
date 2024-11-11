import sys
input = sys.stdin.readline

N = int(input())
T0 = list(map(int, input().split()))
V = list(map(int, input().split()))

INF = 1000
def main():
    Tmax = 0
    T = [0]
    for t in T0:
        Tmax += t
        T.append(Tmax)

    preh = 0
    ans = 0
    for t0 in range(2*Tmax+1):
        t = t0/2
        height = INF
        for n in range(-1, N+1):
            if n == -1:
                t1, t2, v = -1, 0, 0
            elif n == N:
                t1, t2, v = Tmax, Tmax+1, 0
            else:
                t1, t2, v = T[n], T[n+1], V[n]
            
            if t < t1:
                y = v + t1 - t
            elif t1 <= t <= t2:
                y = v
            else:
                y = v + t - t2
            height = min(height, y)
        
        ans += (preh + height)*0.5/2
        preh = height
    print(ans)

if __name__ == "__main__":
    main()