#yeh dil maange more
for i in range(int(input())):
    n,x = map(int,input().split())
    d = [0]*1234567
    for i in range(n-1):
        a,b = map(int,input().split())
        d[a]+=1
        d[b]+=1
    if d[x]<=1:
        print('Ayush')
    else:
        if n&1:
            print('Ashish')
        else:
            print('Ayush')