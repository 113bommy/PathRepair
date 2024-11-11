n=int(input())
a=[int(input()) for i in range(n)]

count=1

for i in range(n):
    if count == 2:
        print(i)
        exit()
    count=a[count-1]

print(-1) 