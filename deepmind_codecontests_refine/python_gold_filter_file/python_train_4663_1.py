def divisor(x):
    div = []
    for i in range(1,int(x**0.5)+1):
        if x%i == 0:
            div.append(i)
            if x != i**2: div.append(x//i)
    
    return div

def calc(n,x):
    if x==1: return n
    while n>=x:
        if n%x == 0:
            n //= x
        else:
            n %= x
    return n

n = int(input())

div_list = divisor(n)
ans = 0

for div in div_list:
    x = calc(n,div)
    if x==1: ans +=1

ans += len(divisor(n-1)) - 1
print(ans)