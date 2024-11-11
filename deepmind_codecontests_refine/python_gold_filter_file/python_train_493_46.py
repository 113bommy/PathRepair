n=int(input())

cnt=0
for i in range(1,n):
    cnt +=(n-1)//i
print(cnt)