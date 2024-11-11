n,d=list(map(int,input().split(' ')))
s=input()
location=0
count=0
while location+1<n:
    last=0
    for i in range(1,d+1):
        if location+i<n and s[location+i]=='1':
            last=i
    if last==0:
        break
    else:
        count+=1
        location+=last
if last==0:
    print(-1)
else:
    print(count)