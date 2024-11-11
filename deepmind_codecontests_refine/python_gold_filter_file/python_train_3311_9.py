R,G,B,N=map(int,input().split())

cnt=0
for i in range(N//R+1):
    for j in range((N-R*i)//G+1):
        if (N-(R*i+G*j))%B==0:
            cnt+=1

print(cnt)