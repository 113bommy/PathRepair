n = input()
for i in range(0,int(n)):
    a, b = input().split() 
    real = abs(int(b)-int(a))
    result = int(real/5)
    rem = real%5
    result += int(rem/2)
    rem = rem%2
    result += rem
    print(result)