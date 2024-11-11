n,k = map(int,input().split())
x = list(map(int,input().split()))
ans = 0
for i in x:
    if str(i).count("4")<=k and str(i).count("7")<=k and str(i).count("4")+str(i).count("7")<=k:
        ans+=1
print(ans)