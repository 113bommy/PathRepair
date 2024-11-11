n, x, y = map(int, input().split())
a = list(map(int, input().split()))
if x>y:
    print(n)
else:
    print((len([ai for ai in a if ai<=x])+1)//2)