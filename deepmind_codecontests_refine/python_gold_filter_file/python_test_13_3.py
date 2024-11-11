t=int(input())
for i in range(t):
    sr=input()
    b=sr.count('B')
    a=sr.count('A')
    c=sr.count('C')
    
    if b==a+c:
        print('YES')
    else:
        print('NO')