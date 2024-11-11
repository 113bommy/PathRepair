def f(n):
    if n<10:
        return n
    q=n//10
    r=n%10
    return (10*q)+f(q+r)
        
n1=int(input())
for i in range(n1):
    n=int(input())
    print(f(n))
    