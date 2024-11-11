k, a, b = map(int, input().split())

if(a%k == 0):
    f = a
else:
    if(a < 0):
        f = a + (-a)%k
    else:
        f = a - ((a)%k) + k
d = k
nth = b - (b%k)

print(((nth - f)//d) + 1)