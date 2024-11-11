M,D=map(int,input().split())
cnt=0
for m in range(1,M+1):
    for d in range(22,D+1):
        if m==(d%10)*(d//10) and (d%10)>=2 and (d//10)>=2:
            cnt+=1
print(cnt)