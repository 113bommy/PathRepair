n = int(input())
for i in range(n):
    a,b,c,d = map(int,input().split())
    if b+c >d:
        print(b,c,d)
    else:
        print(b,c,b+c-1)

    
