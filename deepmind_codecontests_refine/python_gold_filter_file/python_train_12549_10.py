n = int(input())
A = list(map(int,input().split()))

if n==1:
    if A[0]==1:
        print("YES")
    else:
        print("NO")
    exit()

count = 0

for i in range(n):
    if A[i]==0:
        count += 1
    if count > 1:
        break;

if count == 1:
    print("YES")
else:
    print("NO")