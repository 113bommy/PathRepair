n, h = list(map(int, input().split()))
a = list(map(int, input().split()))
count=0
for i in range(n):
    if(a[i]>h):
        count +=2
    else:
        count +=1
print(count)
