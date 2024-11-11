b,g=map(int,input().split())
ans=b+g-1
print(ans)
if b>g:
    for i in range(1,b+1):
        print(i,1)
    for i in range(2,g+1):
        print(1,i)
else:
    for i in range(1,b+1):
        print(i,1)
    for i in range(2,g+1):
        print(1,i)