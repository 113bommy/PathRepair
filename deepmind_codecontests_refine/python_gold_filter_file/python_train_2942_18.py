t=int(input())
for _ in range(t):
    p=int(input())
    if p%2==0:
        print(p//2)
    else:
        print((p-1)//2+1)