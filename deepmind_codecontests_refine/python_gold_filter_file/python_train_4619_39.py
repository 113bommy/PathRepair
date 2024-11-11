n = int(input())
count = 0
for i in range(n):
    ar = list(map(int,input().split()));
    if sum(ar)>=2:
        count+=1
print(count)