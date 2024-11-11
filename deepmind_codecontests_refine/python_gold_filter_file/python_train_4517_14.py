n,k=map(int,input().split(' '))
l=[i for i in range(k+1,0,-1)]
j=[k for k in range(k+2,n+1)]
print(' '.join(map(str,l+j)))
