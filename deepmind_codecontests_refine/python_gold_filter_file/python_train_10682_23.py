params=input().split(" ")
n,k,t=int(params[0]),int(params[1]),int(params[2])
print(min(t,n)-max(t-k,0))