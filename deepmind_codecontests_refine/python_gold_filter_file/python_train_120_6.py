

for i in range(int(input())):
    a , b , c = map(int , input().split())
    s= 0
    while b >= 1 and c >= 2:
        b = b - 1
        c = c - 2
        s = s + 3
    while a >= 1 and b >= 2:
        a = a - 1
        b = b - 2
        s = s + 3
    
    if a < 1 or b < 1 or c < 2:
        print(s)
        
        