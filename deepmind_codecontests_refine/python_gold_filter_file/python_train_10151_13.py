def NOK(a, b):
    old_a, old_b = a, b
    while b != 0:
        a, b = b, a % b
    
    return (old_a * old_b) // a

def NOD(a, b):
    while b != 0:
        a, b = b, a % b
    
    return a 

t, w, b = map(int, input().split())

NOK = NOK(w, b)

ans = (t // NOK) * min(w, b) - 1

ans += min((t - (t // NOK * NOK) + 1), min(w, b))

NOD = NOD(ans, t)
print(ans // NOD, '/', t // NOD, sep='')