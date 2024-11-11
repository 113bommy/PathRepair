a,b,n=map(int,input().split())  
print(max(a-n,0),max(b-max(n-a,0),0))