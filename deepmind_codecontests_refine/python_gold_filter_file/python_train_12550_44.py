#CRAZY COMPUTER(716A)

t,c = map(int,input().split())

l = list(map(int,input().split()))
cnt = 1

for i in range(1,len(l)):
    if l[i] - l[i-1] <= c:
        cnt += 1
    else:
        cnt = 1
print(cnt)