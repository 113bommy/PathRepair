import sys
 
t = int(input())
for _ in range(t):
    b, w= map(int, sys.stdin.readline().split())
    if b > w:
        x = 2
        y = 2
        m1 = w
        m2 = b
    else:
        x = 2
        y = 3
        m1 = b
        m2 = w
    if m2 > m1 * 3 + 1:
        print('NO')
    else:
        print('YES')
        for i in range(m1):
            print(x + 2*i, y)
            print(x + 2*i+1, y)
        for i in range(min(m1, m2-m1)):
            print(x + 2*i, y+1)
        for i in range(min(m1, m2-2*m1)):
            print(x + 2*i, y - 1)
        if m2 == m1*3+1:
            print(x-1, y)
            
        

        

