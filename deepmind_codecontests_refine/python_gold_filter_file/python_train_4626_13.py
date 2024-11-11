n = int(input())
l = []
for _ in range(n):
    l.append(list(map(int, input().split())))
arr = [0]*101
for i in range(1,n):
    arr[l[i][0]]+=1
    arr[l[i][1]]-=1
for i in range(1,101):
    arr[i]=arr[i]+arr[i-1]
cnt=0
for i in range(l[0][0],l[0][1]):
    if arr[i]==0:
        cnt+=1
print(cnt)