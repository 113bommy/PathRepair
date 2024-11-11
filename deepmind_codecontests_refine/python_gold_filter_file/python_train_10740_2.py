from sys import stdin
input = stdin.readline

q = int(input())

for _ in range(q):
    b, w = [int(i) for i in input().split()]
    
    if (w-1)/3 <= b <= (3*w+1):
        print('YES')
        if w < b: v = 0
        else:
            v = 1
            b, w = w, b
            
        for i in range(2*w):
            print(str(i+1) + ' ' + str(2+v))
        
        b -= w
        
        if b % 2 == 1: print(str(2*w+1) + ' ' + str(2+v))
            
        for i in range(b // 2):
            print(str(2*i+2) + ' ' + str(1+v))
            print(str(2*i+2) + ' ' + str(3+v))
                
            
        
    else: print('NO')