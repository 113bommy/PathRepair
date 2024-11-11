i=0
for _ in range(int(input())):
    p,q=map(int,input().split())
    if(q>=p+2):
        i+=1
print(str(i))