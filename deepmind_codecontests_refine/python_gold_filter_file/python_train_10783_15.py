from math import ceil
n,m = map(int,input().split())
if m >= n:
    print(n)
else:
    #num = 0 <= n2**2 + n2 - (n - m)*2
    num2 =  (n - m)*2
    num2 = num2 * 4 + 1.0
    num3 = num2
    num2 = num2 ** 0.5
    num = int((-1 + (num2))/2)
    num -= 1
    while True:
        if (n - m)*2 - (num * (num+1)) <= 0:
            break
        num += 1
    print(num + m)
