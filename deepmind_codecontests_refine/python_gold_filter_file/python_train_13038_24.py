import sys
ints = (int(x) for x in sys.stdin.read().split())
sys.setrecursionlimit(3000)

def main():
    ntc = next(ints)
    for tc in range(1,ntc+1):
        n, m = (next(ints) for i in range(2))
        ans = (m*n+1)//2
        print(ans)
    return

main()

###