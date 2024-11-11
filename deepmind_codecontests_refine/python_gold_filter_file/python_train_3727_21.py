import heapq

N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))

que=[(-B[i],i) for i in range(N)]
heapq.heapify(que)
count=0
while que:
    val,index=heapq.heappop(que)
    if val>0:
        break
    if index!=N-1:
        a,b,c=B[index-1],B[index],B[index+1]
        if a==A[index-1] and c==A[index+1]:
            if B[index]%(a+c)==A[index]%(a+c):
                count+=(B[index]-A[index])//(a+c)
                B[index]=A[index]
            else:
                count=-1
                break
        else:
            if B[index]>a+c:
                count+=B[index]//(a+c)
                B[index]%=a+c
                heapq.heappush(que,(-B[index],index))
    else:
        a,b,c=B[index-1],B[index],B[0]
        if a==A[index-1] and c==A[0]:
            if B[index]%(a+c)==A[index]%(a+c):
                count+=(B[index]-A[index])//(a+c)
                B[index]=A[index]
            else:
                count=-1
                break
        else:
            if B[index]>a+c:
                count+=B[index]//(a+c)
                B[index]%=a+c
                heapq.heappush(que,(-B[index],index))

if A==B:
    print(count)
else:
    print(-1)
