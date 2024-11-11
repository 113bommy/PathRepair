import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    a_s = [0 for _ in range(n)]
    b_s = [0 for _ in range(n)]
    for a in alst:
        a_s[a - 1] += 1
    for b in blst:
        b_s[b - 1] += 1
    for a, b in zip(a_s, b_s):
        if a + b > n:
            print("No")
            return
    print("Yes")
    a_total = 0
    b_total = 0
    cor = -100000
    for a, b in zip(a_s, b_s):
        a_total += a
        cor = max(cor, a_total - b_total)
        b_total += b
    ans = blst[-cor:] + blst[:-cor]
    print(*ans)
        
main()