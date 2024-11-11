n=int(input())

def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    divisors.sort()
    return divisors
d=make_divisors(n)[1:]
l=make_divisors(n-1)[1:]

ans=0
for i in d:
    m=n
    while m%i==0:
        m//=i
    if m%i==1:
        ans+=1
print(ans+len(l))
