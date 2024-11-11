n=int(input())
cnt=0
for i in range(n) :
    arr=[int(j) for j in input().split()]
    if (arr[1]-arr[0])>1 :
        cnt+=1
print(cnt)