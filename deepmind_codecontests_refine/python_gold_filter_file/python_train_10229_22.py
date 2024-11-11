t=int(input())
for _ in range(t):
    a,b,l=map(int,input().split())
    count=0
    while a<=l and b<=l:
        if a<b:
            a+=b
        else:
            b+=a
        count+=1
    print(count)
            