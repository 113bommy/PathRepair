N = int(input())

def divisor(N):
    ret = []
    for i in range(1, int(N**0.5)+1):
        if N % i == 0:
            ret.append(i)
            if N // i != i:
                ret.append(N//i)
    return ret


div_N = divisor(N)
div_N_1 = divisor(N-1)

ans = 0

for k in div_N[1:]:
    n = N
    while n % k == 0:
        n //= k
    if n % k == 1:
        ans += 1

ans += len(div_N_1) - 1

print(ans)
