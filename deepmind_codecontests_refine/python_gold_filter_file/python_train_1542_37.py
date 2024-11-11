n=int(input())
A=list(map(int,input().split()))

B=[0]*(n+1)
C,cnt=[],0
for i in range(1,n+1)[::-1]:
    sum_list=sum([B[j] for j in range(i,n+1,i)])
    if sum_list%2!=A[i-1]:
        B[i]=1
        cnt +=1
        C.append(i)

print(cnt)
print(*C[::-1])