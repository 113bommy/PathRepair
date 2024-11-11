M=10**9+7
n=int(input())
print((pow(10,n,M)-pow(9,n,M)*2+pow(8,n,M))%M)