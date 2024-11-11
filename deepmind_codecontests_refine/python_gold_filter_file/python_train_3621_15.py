N = int(input())
a = [ int(s) - 1 for s in input()]

# r! に含まれる 2 の数
twos = {}
twos[0] = 0
for r in range(1, N):

    count = 0
    tmp = r
    while tmp % 2 == 0:
        tmp //= 2
        count += 1
    
    twos[r] = twos[r-1] + count


# {N-1}_C_r の偶数奇数判定
ncr = {}
for r in range(N):
    if twos[N-1] - twos[N-1-r] - twos[r] > 0:
        ncr[r] = 0
    else:
        ncr[r] = 1


# 答えの判定
oe = 0
for r, ai in enumerate(a):
    oe = (oe + ncr[r] * ai) % 2

if oe == 1:
    print(1)
else:
    if 1 in a:
        print(0)
    else:
        oe2 = 0
        for r, ai in enumerate(a):
            oe2 = (oe2 +ncr[r] * ai // 2 ) %2
        if oe2 == 1:
            print(2)
        else:
            print(0)