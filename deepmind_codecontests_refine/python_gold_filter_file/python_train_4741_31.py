n = int(input())
if n == 1 or n == 2: 
    print(1)
elif n == 3: print(2)
else:
    a = (n // 3)*2
    if n % 3 > 0:
        a+=1
    print(a)
