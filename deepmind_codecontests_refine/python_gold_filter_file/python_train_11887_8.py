import sys
mod = 1000000007
def get_array(): return list(map(int, sys.stdin.readline().split()))
def get_ints(): return map(int, sys.stdin.readline().split())
def input(): return sys.stdin.readline()
def main():
    k = int(input())
    if k % 2 == 0:  print('NO')
    else:
        print('YES')
        n = 2 * k
        ans = [1]*n
        ans[k] = 2
        if n > 2:
            for i in range(k + 1, n):
                if i % 2 == 0: ans[i] = ans[i - 1] + 1
                else: ans[i] = ans[i - 1] + 3
            ans[1] = 4
            for i in range(2, k):
                if i % 2 == 0: ans[i] = ans[i - 1] + 1
                else: ans[i] = ans[i - 1] + 3
        ans = [str(x) for x in ans]
        print(' '.join(ans))
if __name__ == "__main__":
    main()