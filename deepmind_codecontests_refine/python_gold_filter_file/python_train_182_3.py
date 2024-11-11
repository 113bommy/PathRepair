def solve(n,k) :
    if n <= 9 and k == 1 :
        return n
    elif n <= 9 and k >= 2 :
        return 0
    elif k == 0:
        return 1
    else :
        m = n //10
        r = n % 10
        return  r * solve(m,k-1) + (9 - r) * solve(m-1,k-1) + solve(m,k)

n = int(input())
k = int(input())
print(solve(n,k))