k=int(input())
a,b=map(int,input().split())
print('OK' if a//k-b//k or a%k==0 else 'NG')
