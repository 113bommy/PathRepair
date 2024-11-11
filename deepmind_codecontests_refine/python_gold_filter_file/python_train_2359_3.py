n = int(input())
ans = 0
_pow = 2

while 2 * n > _pow:
    ans += (_pow //2 )* (n // _pow + (1 if n % _pow > _pow // 2 else 0))
    _pow *= 2
    
print(ans)
