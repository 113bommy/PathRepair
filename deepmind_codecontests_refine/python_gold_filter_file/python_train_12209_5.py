import sys
# sys.stdin = open("input.txt")


def main():
    T = int(input())
    for ti in range(T):
        n, k = map(int, input().split())
        A = [int(a) for a in input().split()]
        c = 0
        m = k / 2
        ans = []
        for a in A:
            if a < m:
                ans.append(1)
            elif a > m:
                ans.append(0)
            elif c == 0:
                ans.append(0)
                c = 1 - c
            else:
                ans.append(1)
                c = 1 - c
        print(" ".join(map(str, ans)))

if __name__ == "__main__":
    main()
