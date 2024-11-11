def gcd(x, y): 
    while(y): 
        x, y = y, x % y 
    return x 
   
n, k = list(map(int, input().split(" ")))

if(k > 42):
    print("No")
else:
    x = 1
    for i in range(1, k + 1):
        x = x * i // gcd(x, i)
    if((n + 1) % x == 0):
        print("Yes")
    else:
        print("No")

