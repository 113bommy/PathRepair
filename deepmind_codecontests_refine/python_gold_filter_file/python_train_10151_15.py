t,w,b = map(int,input().split())

def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 

def lcm(a,b): 
    return (a // gcd(a,b))*b

l = lcm(w,b)
# print(l)
a = t//l
x = a*(min(w,b)-1) + a
if t%l!=0:
    x = a*(min(w,b)-1) + a
    if min(w,b)<=t%l:
        x += min(w,b)-1
    else:
        x+= t%l
# print(a)

y = gcd(x,t)
print(str(x//y)+'/'+str(t//y))

