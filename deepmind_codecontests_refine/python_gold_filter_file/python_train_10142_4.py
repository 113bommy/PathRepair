(a,b)=map(int, input().split())
ans1=0
ans2=0
ans0=0
for i in range(1,7):
    if abs(i-a)>abs(i-b):
        ans1+=1
    elif abs(i-a)<abs(i-b):
        ans2+=1
    else:
        ans0+=1
print(ans2,ans0,ans1)