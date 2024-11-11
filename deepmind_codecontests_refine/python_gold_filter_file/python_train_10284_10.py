k=int(input())
a,b=map(int,input().split())
print('OK' if -(-a//k)<=b//k else 'NG')