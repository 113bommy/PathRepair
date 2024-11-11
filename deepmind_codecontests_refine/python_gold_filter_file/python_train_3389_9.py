a,b=map(int,input().split())
pp=True
for i in range(a):
    gg=str(input())
    for j in gg:
        if j=="C" or j=="M" or j=="Y":
            pp=False
            break
if pp==False:
    print("#Color")
else:
    print("#Black&White")