n = int(input())
s = int(input())

def f(b, n) :
    ret = 0
    while n != 0 :
        ret += n % b
        n //= b
        
    return ret

def solve(n, s) :
    if n == s :
        return n + 1
    if s > n :
        return -1
    
    b = 2
    while b * b <= n :
        if f(b, n) == s :
            return b
        b += 1
            
    p = int(-(-(n ** 0.5 - 1) // 1))
    while p > 0 :
        if (n - s) % p == 0 :
            b = 1 + (n - s) // p
            if p < b and 0 <= s - p < b :
                return b
            
        p -= 1
        
    return -1
            
print(solve(n, s))