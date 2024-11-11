import sys
input = sys.stdin.readline
import heapq as hp


def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    q = []
    for i, b in enumerate(B):
        hp.heappush(q, (-b, i))

    c = 0
    while q:
        #print(q)
        _, ind = hp.heappop(q)
        b = B[ind]
        if ind == N-1:
            s = B[ind-1]+B[0]
        else:
            s = B[ind-1]+B[ind+1]
        #print(b, s)
        if (b-A[ind])%s == 0:
            B[ind] = A[ind]
            c += (b-A[ind])//s
        elif b%s <= A[ind] or b < s:
            c = -1
            break
        else:
            c += b//s
            B[ind] = b%s
            hp.heappush(q, (-B[ind], ind))

    print(c)

if __name__ == "__main__":
    main()