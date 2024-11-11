k=int(input())
a,b=map(int,input().split())
print("OK" if (a-1)//k!=b//k else 'NG')