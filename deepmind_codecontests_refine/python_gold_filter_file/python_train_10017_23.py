n = int(input())
l = list(map(int,input().split()))
s = sum(l)
count = 0
for i in l:
    if (s-i)%2==0:
        count+=1
print(count)