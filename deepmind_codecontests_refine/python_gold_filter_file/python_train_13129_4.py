"""https://codeforces.com/contest/1082/problem/A"""
for _ in range(int(input())):
    n, x, y, d = tuple(map(int, input().split()))
    start = x%d
    end = y%d
    
    init = 1
    last = n%d
    if start==end:
        print( abs(y-x)//d )
    elif init!=end and last!=end:
        print(-1)
    else:
        if init==last:
            print( min( (x+d-2)//d + (y+d-2)//d, (n-x+d-1)//d + (n-y+d-1)//d  ) )
        elif init==end:
            print( (x+d-2)//d + (y+d-2)//d )
        else:
            print( (n-x+d-1)//d + (n-y+d-1)//d )        