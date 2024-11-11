from collections import defaultdict
from math import gcd

def main():
    N = int(input())
    MOD = 10 ** 9 + 7
    zero = 0
    d = defaultdict(lambda: defaultdict(int))
    for i in range(N):
        A, B = map(int, input().split())
        if A == 0 and B == 0:
            zero += 1
            continue
        if B < 0:
            A = -A
            B = -B
        flag = False
        if A <= 0:
            A, B = B, -A
            flag = True
        g = gcd(A,B)
        A //= g
        B //= g
        if flag:
            d[(A,B)]['first'] += 1
        else:
            d[(A,B)]['second'] += 1
    ans = 1
    for i, j in d.items():
        now = 1
        now += pow(2,j['first'],MOD) - 1
        now += pow(2,j['second'],MOD) - 1
        ans *= now
        ans %= MOD
    ans -= 1
    ans += zero
    ans %= MOD
    print(ans)




    

if __name__ == "__main__":
    main()