
q = int(input())

for _ in range(q):
    a,b,c,d = map(int,input().split())
    if (b-a)%(c+d)==0:
        print((b-a)//(c+d))
    else:
        print(-1)