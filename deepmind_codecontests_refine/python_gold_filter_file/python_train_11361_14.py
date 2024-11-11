t=int(input())
s='abcdefghijklmnopqrstuvwxyz'
for i in range(t):
    n,k=map(int,input().split())
    c=1
    while(c):
        if(n>=k):
            print(s[:k],end='')
            n-=k
        else:
            print(s[:n],end='')
            c=0
    print('')
