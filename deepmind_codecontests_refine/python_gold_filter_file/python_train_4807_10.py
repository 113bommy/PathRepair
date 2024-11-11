n = int(input())
l = list(map(int,input().split()))
l.sort()
k = l[::2]+l[1::2][::-1]
#print(k)
for i in range(n):
    if k[i-1]>=k[i-2]+k[i]:
        print('NO')
        exit()
print('YES')
for i in k:
    print(i,end=' ')