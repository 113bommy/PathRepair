n, a, b = map(int, input().split())
if (b-a)%2==0:
    print((b-a)//2)
else:
    print(min(n-b+1+(b-a-1)//2,a+(b-a)//2))