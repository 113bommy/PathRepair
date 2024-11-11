n=int(input())
avail=0
for i in range(n):
    a,b=map(int,input().split())
    if (a+1)<b:
        avail+=1
print(avail)
