m,d=map(int,input().split())
cnt=0
for i in range(1,d+1):
    d10=i//10
    d1=i-(10*d10)
    if d1>=2 and d10>=2:
        if m>=d1*d10:
            cnt+=1
print(cnt)