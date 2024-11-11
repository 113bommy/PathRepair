N=int(input())
ans=[]
for i in range(1,int(N**.5)+2):
    if N%i<1:
        ans.append(N//i+i-2)
print(min(ans))