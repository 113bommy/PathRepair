a,b,c,x=[int(input()) for i in range(4)]
i=0
for _ in range(a+1):
    for j in range(b+1):
        for k in range(c+1):
            if 500*_+100*j+50*k==x:
                i+=1
print(i)