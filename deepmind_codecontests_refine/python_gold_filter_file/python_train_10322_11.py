n=int(input())
p=input().split()
i=n
while p[i-1]==p[n-1]:
    i-=1
print(i)
