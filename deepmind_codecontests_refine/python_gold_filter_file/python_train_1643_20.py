def popcount(x):
    return bin(x).count("1")
def solve(n):
    if n == 0:
        return 0
    return 1+solve(n % popcount(n))

N = int(input())
X = input()
num_x = int(X, 2)
p_cnt = X.count('1')
if p_cnt == 1:
    for i in range(N):
        if X[i] == '1':
            print(0)
        elif i == N-1:
            print(2)
        else:
            print(1)
    exit()
r0_p = num_x % (p_cnt+1)
r0_m = num_x % (p_cnt-1)
for i in range(N):
    if X[i] == '0':
        c_p_cnt = p_cnt+1
        r = (r0_p + pow(2, (N - 1 - i), c_p_cnt)) % c_p_cnt
    else:
        c_p_cnt = p_cnt-1
        if c_p_cnt == 0:
            print(0)
            continue
        r = (r0_m- pow(2, (N - 1 - i), c_p_cnt)) % c_p_cnt
    print(1 + solve(r % c_p_cnt))

