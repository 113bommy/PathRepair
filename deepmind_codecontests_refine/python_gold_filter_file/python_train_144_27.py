a,b=map(int,input().split())
s=list(map(int,input().split()))
x=0;razn=0
for i in range(a-1):
    if s[i]>s[i+1]:
        x=s[i]-s[i+1]
        razn=max(razn,x)
print(max(razn-b,0))