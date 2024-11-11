v=int(input(), 36)
x=v//36-9
y=v%36
ans=0
for i in range(-1, 2):
    for j in range(-1, 2):
        if (i!=0 or j!=0) and x+i in range(1, 9) and y+j in range(1, 9):
            ans+=1
print(ans)