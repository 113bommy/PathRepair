n  = int(input())
li = list(map(int,input().split()))
a,b  = map(int,input().split())
c = b-a
y  = 0
for i in range(a-1,b-1):
    y += li[i]
print(y)