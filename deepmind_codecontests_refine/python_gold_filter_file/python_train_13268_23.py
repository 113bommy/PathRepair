n = int(input())
j = 0
for i in range(n):
    a,b=map(int,input().split())
    if a+1 < b:
        j += 1
print(j)