import heapq

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        KLR = [tuple(map(int, input().split())) for _ in range(N)]
        KLR.sort()
        H = []
        T = []
        s = 0
        for k, l, r in KLR:
            s += r
            if l - r >= 0:
                heapq.heappush(H, (l - r, k))
                while len(H) > k:
                    T.append(heapq.heappop(H))
            else:
                T.append((l - r, k))
        s += sum(l for l, k in H)
        H = []
        T.sort(key = lambda x: -x[1])
        for l, k in T:
            heapq.heappush(H, (-l, N - k))
            while len(H) > N - k:
                s -= heapq.heappop(H)[0]

        print(s)
main()
