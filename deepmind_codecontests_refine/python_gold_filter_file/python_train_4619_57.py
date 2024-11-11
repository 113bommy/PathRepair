n=int(input())
cc=0
for i in range(n):
    a,b,c=map(int,input().split())
    if a+b+c>=2:
        cc+=1
print(cc)
