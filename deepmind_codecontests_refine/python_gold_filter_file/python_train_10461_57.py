k,n,w=map(int,input().split())
print(max(int(k*w*(w+1)/2-n),0))