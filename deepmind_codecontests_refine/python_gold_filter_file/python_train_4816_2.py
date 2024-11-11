import sys
input = sys.stdin.buffer.readline

def iinp() -> int: return int(input())
def linp() -> list: return [int(p) for p in input().split()]
def sinp() : return input().decode('unicode-escape')[0:-2]
# M = int(1e9 + 7)



for _ in range(iinp()):
    n = iinp()
    s = sinp()
    sums, ans = 0, 0
    for c in s:
        if c == '(':
            sums -= 1
        else:
            sums += 1
        ans = max(ans, sums)
    print(ans)




