n = int(input())
x = 1
y = n - 1

def is_prime(a):
    x = True 
    for i in range(2, a):
        if a%i == 0:
            x = False
            break
    return x

while x < n:
    if x+y == n and not is_prime(x) and not is_prime(y):
        print("{} {}".format(x,y))
        break
    x+=1
    y-=1

        