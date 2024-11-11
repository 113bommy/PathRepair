R,G,B,n=map(int,input().split())
count=0
for r in range(n+1):
    for g in range(n+1):
            if n>=r*R+g*G and (n-r*R-g*G)%B==0:
                count+=1
print(count)