import sys
import math
import bisect

def backtrack(cur, val, A):
    if cur and cur <= 9:
        A.append(val)
    if cur == 9:
        return
    backtrack(cur + 1, val * 10 + 4, A)
    backtrack(cur + 1, val * 10 + 7, A)

def solve(n):
    A = []
    backtrack(0, 0, A)
    A.sort()
    #print(A)
    for i in range(len(A)+1):
        if A[i] == n:
            return i + 1
    return -1

def main():
    n = int(input())
    ans = solve(n)
    print(ans)

if __name__ == "__main__":
    main()
