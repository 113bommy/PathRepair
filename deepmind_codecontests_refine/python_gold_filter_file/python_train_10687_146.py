j = input().split(' ')
n = int(j[0])
k=int(j[1])


for i in range(k):
    if n % 10 == 0:
        n = n/10
    else:
        n-=1
print(int(n))