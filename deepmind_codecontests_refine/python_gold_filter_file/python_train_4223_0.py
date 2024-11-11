#x(t+ka-kb) + bd - t
def f(x, d, k, a, b, t):
    return x*(t+k*a-k*b) + b*d - t

d, k, a, b, t = map(int, input().split())
X = d // k

if X < 1:
    print(d*a)
else:
    if t+k*a-k*b < 0:
        print(min(X*t + d*a, f(X, d, k, a, b, t)))
    else:
        print(min(d*b, f(1, d, k, a, b, t)))
        
    
# 5 2 1 4 10   
# 5 2 1 4 5