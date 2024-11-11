q = int(input())
for tc in range(q):
    l,r,d = map(int,input().split())
    if d < l or d > r:
        print( d )
    else:
        print(d*((r)//d+1))
