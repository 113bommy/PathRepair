k,n,w=map(int,input().split())
value=0
for i in range(w+1):
    value+=k*i
print(max(0,value-n))