N,A,B=map(int,input().split())
if (B-A)%2==0:
    print((B-A)//2)
else:
    print(min((B+A-1)//2,((2*N-B+1-A)//2)))