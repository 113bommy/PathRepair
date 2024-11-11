def third_root(q):
    x=q/2
    while abs(x**3-q)>=q*10**(-5):
        x=x-(x**3-q)/(3*x**2)
    return x
while 1:
    q=eval(input())
    if q==-1:break
    ans=third_root(q)
    print(ans)