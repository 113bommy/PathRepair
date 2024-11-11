k,n,w=map(int,input().split())
c=0
for i in range(1,w+1):
    c+=i*k
print(max(c-n,0))

    