N = int(input())
count = 0
for i in range(N):
    l = list(map(int,input().split()))
    if sum(l)>1:
        count+=1
print(count)