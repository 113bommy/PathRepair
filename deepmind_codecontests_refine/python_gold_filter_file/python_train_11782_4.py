l=int(input())
for i in range (0,l):
    k,n,a,b=map(int,input().split())
    if k/b<=n:
        print(-1)
    else:
        print(min(-int(-k/a),n,int((k-n*b-1)/(a-b))))



