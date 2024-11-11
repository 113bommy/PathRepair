t = int(input())

for _ in range(t):
    n,m,x,y = map(int,input().split())
    total = 0
    for i in range(n):
        squares = input().split('*')
        for s in squares:
            l = len(s)
            if l==1:
                total +=x
            else:
                if y >= 2*x:
                    total += x*l
                else:
                    total += y*(l//2) + x*(l%2)
    print(total)