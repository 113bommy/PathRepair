n = int(input())
a = list(map(int,input().split()))
b = [a[0]]
mx = a[0]
for i in range(1,n):
    b.append(a[i]+mx)
    mx=max(mx,b[-1])
for i in b:
    print(i,end=' ')
print()