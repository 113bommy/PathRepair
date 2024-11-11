a,b,k=map(int,input().split())
a,b = max(0,a-k) , max(b-max(k-a,0),0)
print(a,b)