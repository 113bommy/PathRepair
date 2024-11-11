modd = 1000000007


def solve():
    n, k = list(map(int, input().split()))
    bi = bin(k)[2:]
    return sum(pow(n, len(bi) - i - 1, modd) for i in range(len(bi)) if bi[i] == '1') % modd


t = int(input())
while t:
    t -= 1
    print(solve())
