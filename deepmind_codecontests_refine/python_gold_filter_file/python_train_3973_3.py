n,k=map(int,input().strip().split())
d=(n-k)//2+1
x=['1' if (i+1)%d==0 else '0' for i in range(n)]
print(''.join(x))