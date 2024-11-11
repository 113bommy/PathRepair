import sys
input = sys.stdin.readline


def main():
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = [int(x) for x in input().split()]

        A.sort()
        ans = []
        for i in range(N // 2):
            ans.append(A[-i - 1])
            ans.append(A[i])
        if N % 2 == 1:
            ans.append(A[N // 2])

        print(*reversed(ans))


        
        
    

if __name__ == '__main__':
    main()


